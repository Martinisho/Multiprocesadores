#include <stdio.h>
#include <math.h>
#include <time.h>

long N = 50000;
FILE *fptr0;
FILE *fptr1;
FILE *fptr2;
FILE *fptr3;

double h,t,w,ab,k1,k2,k3,k4;
double w0 = M_PI / 4, a = 0, b = M_PI;
int i;


int main()
{
   time_t begin, end;
   time(&begin);
   //******************* Equation 1 ********************************
   fptr0 = fopen("Act_1_6_Eq1_sec.txt","w");
 	fprintf(fptr0, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
   w = w0;
   fprintf(fptr0, "%f\t %f\n", a, w);
   for(i=0;i<N;i++){
      h=(b - a) / N;
      t=(h * i);
      k1 = h * ( (t * exp(3.0 * t)) - (2.0 * w) );
      k2 = h * ( ( (t + (h / 2.0)) * exp(3.0 * (t + (h / 2.0)))) - (2.0 * (w + (k1 / 2.0))) );
      k3 = h * ( ( (t + (h / 2.0)) * exp(3.0 * (t + (h / 2.0)))) - (2.0 * (w + (k2 / 2.0))) );
      k4 = h * ( ( (t + (1.0)) * exp(3.0 * (t + (h / 2.0)))) - (2.0 * (w + (k3))) );
      w = w + ( (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4) );
      printf("%f \n", w);
      fprintf(fptr0, "%f\t %f \t \n", t+h, w);
   }
   fclose(fptr0);

   //******************* Equation 2 ********************************
   fptr1 = fopen("Act_1_6_Eq2_sec.txt","w");
 	fprintf(fptr1, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
   w = w0;
   fprintf(fptr1, "%f\t %f\n", a, w);
   for(i=0;i<N;i++){
      h=(b-a)/N;
      t=(h * i);
      k1 = h * ( 1 + pow( t - w , 2.0 ) );
      k2 = h * ( 1 + pow( (t + (h / 2.0)) - (w + (k1 / 2.0)) , 2.0 ) );
      k3 = h * ( 1 + pow( (t + (h / 2.0)) - (w + (k2 / 2.0)) , 2.0 ) );
      k4 = h * ( 1 + pow( (t + (1)) - (w + (k3)) , 2.0 ) );
      w = w + ( (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4) );
      printf("%f \n", w);
      fprintf(fptr1, "%f\t %f \t \n", t+h, w);
   }
    fclose(fptr1);

   //******************* Equation 3 ********************************
   fptr2 = fopen("Act_1_6_Eq3_sec.txt","w");
 	fprintf(fptr2, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
   w = w0;
   fprintf(fptr2, "%f\t %f\n", a, w);
   for(i=0;i<N;i++){
      h=(b-a)/N;
      t=(h * i);
      k1 = h * ( 1 + (  w / t ) );
      k2 = h * ( 1 + ( (w + (k1 / 2.0)) / (t + (h / 2.0)) ) );
      k3 = h * ( 1 + ( (w + (k2 / 2.0)) / (t + (h / 2.0)) ) );
      k4 = h * ( 1 + ( (w + (k3)) / (t + (1)) ) );
      w = w + ( (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4) );
      printf("%f \n", w);
      fprintf(fptr2, "%f\t %f \t \n", t+h, w);
   }
   fclose(fptr2);

   //******************* Equation 4 ********************************
   fptr3 = fopen("Act_1_6_Eq4_sec.txt","w");
 	fprintf(fptr3, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
   w = w0;
   fprintf(fptr3, "%f\t %f\n", a, w);
   for(i=0;i<N;i++){
      h=(b-a)/N;
      t=(h * i);
      k1 = h * ( cos( 2 * t * w) + sin( 3 * t * w) );
      k2 = h * ( cos( 2 * (t + (h / 2.0)) * (w + (k1 / 2.0))) + sin( 3 * (t + (h / 2.0)) * (w + (k1 / 2.0))) );
      k3 = h * ( cos( 2 * (t + (h / 2.0)) * (w + (k2 / 2.0))) + sin( 3 * (t + (h / 2.0)) * (w + (k2 / 2.0))) );
      k4 = h * ( cos( 2 * (t + (1)) * (w + (k3))) + sin( 3 * (t + (1)) * (w + (k3))) );
      w = w + ( (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4) );
      printf("%f \n", w);
      fprintf(fptr3, "%f\t %f \t \n", t+h, w);
   }
   fclose(fptr3);

   time(&end);
   time_t elapsed = end - begin;

   printf("Elapsed time : %ld seconds \n", elapsed);
}
