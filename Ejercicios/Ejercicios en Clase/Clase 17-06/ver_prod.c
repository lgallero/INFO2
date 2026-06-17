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
    FILE*fp = fopen("productos.dat", "rb");
    Producto p;
    int tam;
    fseek(fp,0,SEEK_END);
    tam = ftell(fp)/sizeof(Producto);
    printf("\n\nCantidad de productos: %d\n\n", tam);
    
    rewind(fp);

    while (fread(&p, sizeof(Producto), 1, fp) == 1) {
        printf("Codigo: %3d |   Precio: $%7.3f  | Descripcion: %-10s |   Cant. Ventas : %3d  \n", p.codigo, p.precio, p.descripcion, p.cant_ventas);
    }

    printf("\n\n");
    fclose(fp);
    return 0;

}