#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *image, *outputImage, *lecturas;
    FILE *data;
    image = fopen("Haachama.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("img2_dd.bmp","wb");    //Imagen transformada
    data = fopen("Image_data.txt","w");    //Imagen transformada
    long ancho;
    long alto;
    unsigned char r, g, b;               //Pixel
    unsigned char* ptr;
    int pixelr[255], pixelg[255], pixelb[255], pixelgray[255];
    for (int i = 0; i < 256; i++)
    {
      pixelb[i] = 0;
      pixelg[i] = 0;
      pixelr[i] = 0;
      pixelgray[i] = 0;
    }

    unsigned char xx[54];
    int cuenta = 0;
    for(int i=0; i<54; i++) {
      xx[i] = fgetc(image);
      fputc(xx[i], outputImage);   //Copia cabecera a nueva imagen
    }
    ancho = (long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
    alto = (long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];
    printf("largo img %li\n",alto);
    printf("ancho img %li\n",ancho);

    //ptr = (unsigned char*)malloc(alto*ancho*3* sizeof(unsigned char));

    while(!feof(image)){
      b = fgetc(image);
      g = fgetc(image);
      r = fgetc(image);
       
      // Devuelve los valores RGB de todos los pixeles
      //fprintf(data, "%d    %d     %d\n", b,g,r);
      pixelb[b]++;
      pixelg[g]++;
      pixelr[r]++;


      unsigned char pixel = 0.21*r+0.72*g+0.07*b;
      pixelgray[pixel]++;
      // Devuelve los valores en escala de grises de todos los pixeles
      //fprintf(data, "%d \n", pixel);

      //ptr[cuenta]= pixel; //b
      //ptr[cuenta+1] = pixel; //g
      //ptr[cuenta+2] = pixel; //r


      //cuenta++;

    }                                        //Grises
    //cuenta = ancho;
    /*for (int i = 0; i < alto*ancho*3; ++i) {
      fputc(ptr[i+(cuenta*3)+2], outputImage);
      fputc(ptr[i+(cuenta*3)+1], outputImage);
      fputc(ptr[i+(cuenta*3)], outputImage);
      cuenta--;
      if (cuenta == 0){
        cuenta = ancho;
      }
    } */

    // Devuelve los arreglos de frecuencia
    for (int i = 0; i < 256; i++)
    {
      fprintf(data, "%d        %d       %d      %d\n", pixelb[i], pixelg[i], pixelr[i], pixelgray[i]);
    }
  
    //free(ptr);
    fclose(image);
    fclose(outputImage);
    return 0;
}
