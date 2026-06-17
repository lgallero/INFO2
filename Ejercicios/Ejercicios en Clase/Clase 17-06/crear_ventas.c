#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int codigo;
    int cant_ventas;
} Ventas;


int main()
{   
    Ventas P[6] = { 
        {1000,5},
        {1010,2},
        {1010,3},
        {1000,5},
        {1030,6},
        {1030,3}
    };

    FILE *fp = fopen("ventas.dat", "wb");
    if (!fp) {
        perror("No se pudo abrir el archivo");
        exit(1);
    }

    fwrite(&P,sizeof(Ventas),6,fp);
    fclose(fp);
    return 0;
}