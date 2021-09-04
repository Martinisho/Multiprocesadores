#include <stdio.h>
#include<omp.h>
#include <math.h>
FILE *fptr0;
FILE *fptr1;
FILE *fptr2;
FILE *fptr3;
FILE *fptr4;
FILE *fptr5;
FILE *fptr6;
FILE *fptr7;
#define NUM_THREADS 8


void Kutta_Eq1(long N, FILE *ptr){
    fprintf(ptr, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
    double h,t,w,ab,k1,k2,k3,k4;
    double w0 = M_PI / 4, a = 0, b = M_PI;
    int i;
    w = w0;
    fprintf(ptr, "%f\t %f\n", a, w);
    for(i=0;i<N;i++){
        h=(b - a) / N;
        t=(h * i);
        k1 = h * ( (t * exp(3.0 * t)) - (2.0 * w) );
        k2 = h * ( ( (t + (h / 2.0)) * exp(3.0 * (t + (h / 2.0)))) - (2.0 * (w + (k1 / 2.0))) );
        k3 = h * ( ( (t + (h / 2.0)) * exp(3.0 * (t + (h / 2.0)))) - (2.0 * (w + (k2 / 2.0))) );
        k4 = h * ( ( (t + (1.0)) * exp(3.0 * (t + (h / 2.0)))) - (2.0 * (w + (k3))) );
        w = w + ( (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4) );
        printf("%f \n", w);
        fprintf(ptr, "%f\t %f \t \n", t+h, w);
    }
    fclose(ptr);
}

void Kutta_Eq2(long N, FILE *ptr){
    fprintf(ptr, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
    double h,t,w,ab,k1,k2,k3,k4;
    double w0 = M_PI / 4, a = 0, b = M_PI;
    int i;
    w = w0;
    fprintf(ptr, "%f\t %f\n", a, w);
    for(i=0;i<N;i++){
        h=(b-a)/N;
        t=(h * i);
        k1 = h * ( 1 + pow( t - w , 2.0 ) );
        k2 = h * ( 1 + pow( (t + (h / 2.0)) - (w + (k1 / 2.0)) , 2.0 ) );
        k3 = h * ( 1 + pow( (t + (h / 2.0)) - (w + (k2 / 2.0)) , 2.0 ) );
        k4 = h * ( 1 + pow( (t + (1)) - (w + (k3)) , 2.0 ) );
        w = w + ( (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4) );
        printf("%f \n", w);
        fprintf(ptr, "%f\t %f \t \n", t+h, w);
    }
    fclose(ptr);
}

void Kutta_Eq3(long N, FILE *ptr){
    fprintf(ptr, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
    double h,t,w,ab,k1,k2,k3,k4;
    double w0 = M_PI / 4, a = 0, b = M_PI;
    int i;
    w = w0;
    fprintf(ptr, "%f\t %f\n", a, w);
    for(i=0;i<N;i++){
        h=(b-a)/N;
        t=(h * i);
        k1 = h * ( 1 + (  w / t ) );
        k2 = h * ( 1 + ( (w + (k1 / 2.0)) / (t + (h / 2.0)) ) );
        k3 = h * ( 1 + ( (w + (k2 / 2.0)) / (t + (h / 2.0)) ) );
        k4 = h * ( 1 + ( (w + (k3)) / (t + (1)) ) );
        w = w + ( (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4) );
        printf("%f \n", w);
        fprintf(ptr, "%f\t %f \t \n", t+h, w);
    }
    fclose(ptr);
}

void Kutta_Eq4(long N, FILE *ptr){
    fprintf(ptr, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
    double h,t,w,ab,k1,k2,k3,k4;
    double w0 = M_PI / 4, a = 0, b = M_PI;
    int i;
    w = w0;
    fprintf(ptr, "%f\t %f\n", a, w);
    for(i=0;i<N;i++){
        h=(b-a)/N;
        t=(h * i);
        k1 = h * ( cos( 2 * t * w) + sin( 3 * t * w) );
        k2 = h * ( cos( 2 * (t + (h / 2.0)) * (w + (k1 / 2.0))) + sin( 3 * (t + (h / 2.0)) * (w + (k1 / 2.0))) );
        k3 = h * ( cos( 2 * (t + (h / 2.0)) * (w + (k2 / 2.0))) + sin( 3 * (t + (h / 2.0)) * (w + (k2 / 2.0))) );
        k4 = h * ( cos( 2 * (t + (1)) * (w + (k3))) + sin( 3 * (t + (1)) * (w + (k3))) );
        w = w + ( (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4) );
        printf("%f \n", w);
        fprintf(ptr, "%f\t %f \t \n", t+h, w);
    }
    fclose(ptr);
}

int main()
{
    const double startTime = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section //Kutta 0
            {
                Kutta_Eq1(50000 , fopen("Act_1_6_Eq1.txt","w"));
            }
            #pragma omp section //Kutta 1
            {
                Kutta_Eq2(50000 , fopen("Act_1_6_Eq2.txt","w"));
            }
            #pragma omp section //Kutta 2
            {
                Kutta_Eq3(50000 , fopen("Act_1_6_Eq3.txt","w"));
            }
            #pragma omp section //Kutta 3
            {
                Kutta_Eq4(50000 , fopen("Act_1_6_Eq4.txt","w"));
            }
        }
    }
    const double endTime = omp_get_wtime();
    printf("tomo (%lf) segundos\n", (endTime - startTime));
}
