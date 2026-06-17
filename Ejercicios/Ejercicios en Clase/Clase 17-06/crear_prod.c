#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int codigo;
    float precio;
    char descripcion[51];
    int cant_ventas;
} Producto;


int main()
{   
    Producto P[4] = { 
        {1000,150.000,"A",0},
        {1010,100.000,"B",0},
        {1020,99.999,"C",0},
        {1030,125.000,"D",0}
    };
    FILE *fp = fopen("productos.dat", "wb");
    if (!fp) {
        perror("No se pudo abrir el archivo");
        exit(1);
    }

    fwrite(&P,sizeof(Producto),4,fp);

    fclose(fp);
    return 0;
}
