#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main()
{
    int NUM_THREADS = 1;
    while (NUM_THREADS <= 800){
    
        double t1, t2, tiempo;
        omp_set_num_threads(NUM_THREADS);
        const double startTime = omp_get_wtime();
        printf("Numero de THREADS: %d. ", NUM_THREADS);

        FILE *image, *outputImage, *lecturas;
        image = fopen("Haachama.bmp","rb");          //Imagen original a transformar
        outputImage = fopen("G_img.bmp","wb");    //Imagen transformada
        long ancho;
        long alto;
        unsigned char r, g, b;               //Pixel
        unsigned char* ptr;

        unsigned char xx[54];
        int cuenta = 0;
        for(int i=0; i<54; i++) {
        xx[i] = fgetc(image);
        fputc(xx[i], outputImage);   //Copia cabecera a nueva imagen
        }

        ancho = (long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
        alto = (long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];
        //printf("Largo img %li\n",alto);
        //printf("Ancho img %li\n",ancho);

        ptr = (unsigned char*)malloc(alto*ancho*3* sizeof(unsigned char));

        while(!feof(image)){
        b = fgetc(image);
        g = fgetc(image);
        r = fgetc(image);

        unsigned char pixel = 0.21*r+0.72*g+0.07*b;
        ptr[cuenta] = pixel; //b
        ptr[cuenta+1] = pixel; //g
        ptr[cuenta+2] = pixel; //r
        
        cuenta++;
        }                                        //Grises

        # pragma omp parallel
        {
            cuenta = ancho;
            # pragma omp for schedule(dynamic)
            for (int i = 0; i < alto*ancho*3; ++i) {
                fputc(ptr[i+2], outputImage);
                fputc(ptr[i+1], outputImage);
                fputc(ptr[i], outputImage);
                cuenta--;
                if (cuenta == 0){
                    cuenta = ancho;
                }
            }
        }

        free(ptr);
        fclose(image);
        fclose(outputImage);

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
    return 0;
}