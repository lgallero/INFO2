#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int codigo;
    int cant_ventas;
} Ventas;


int main()
{
    FILE*fp = fopen("ventas.dat", "rb");
    Ventas p;
    int tam;
    fseek(fp,0,SEEK_END);
    tam = ftell(fp)/sizeof(Ventas);
    printf("\n\nCantidad de Ventas: %d\n\n", tam);
    
    rewind(fp);

    while (fread(&p, sizeof(Ventas), 1, fp) == 1) {
        printf("Codigo: %3d | Cant. Ventas : %3d  \n", p.codigo, p.cant_ventas);
    }

    printf("\n\n");
    fclose(fp);
    return 0;

}