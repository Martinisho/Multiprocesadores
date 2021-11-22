#include <stdio.h>
#include <math.h>
#include <time.h>
#include<omp.h>

static long num_pasos = 100000000; double paso;

int main()
{
    int NUM_THREADS = 1;
//................Threads definition............    
    while (NUM_THREADS <= 800){

        
    //................Area variables...........
        int i, nthreads;
        double pi, sum[NUM_THREADS], t1, t2, tiempo;
        paso = 1.0 / num_pasos;
        const double startTime = omp_get_wtime();
        omp_set_num_threads(NUM_THREADS);
        printf("Numero de THREADS: %d. ", NUM_THREADS);
        
        #pragma omp parallel
        {
            int i, id, nthrds;
            double x;
            
            id = omp_get_thread_num();
            nthrds = omp_get_num_threads();

            if(id == 0){
                nthreads = nthrds;
            }
            for (i = id, sum[id] = 0.0 ; i < num_pasos; i = i + nthrds){
                x = (i + 0.5) * paso;
                //printf("%f \n", x);
                sum[id] += 4.0 / (1.0 + x * x);
            }
        }

        const double endTime = omp_get_wtime();
        printf("tomo (%lf) segundos\n", (endTime - startTime));
        
        if(NUM_THREADS < 100 && NUM_THREADS >=20){
            NUM_THREADS = NUM_THREADS + 9;
        }
        if (NUM_THREADS >= 100){
            NUM_THREADS = NUM_THREADS + 49;
        }
        if (NUM_THREADS > 99 && NUM_THREADS < 9){
            //NUM_THREADS = NUM_THREADS * 10 - 1;
        }
        else{
            NUM_THREADS++;
        }
    }
    /*for (i = 0, pi = 0.0; i < nthreads; i++){
        pi += sum[i] * paso;
    }
    printf("pi = (%lf)\n", pi);
    */
}