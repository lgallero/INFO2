
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int cod;
    float pre;
    char desc[51];
}Productos;

int main()
{
    FILE *archProd;
    Productos p;

    archProd=fopen("Productos.dat","rb");

    if(archProd==NULL)
    {
        printf("\nError al abrir el archivo para lectura...");
        exit(1);
    }

    fread(&p,sizeof(Productos),1,archProd);
    printf("\n%-8s %-10s %-50s","Codigo","Precio","Descripcion");
    printf("\n-------------------------------------");
    while(!feof(archProd))
    {
        printf("\n%-8d %-10.2f %-50s",p.cod,p.pre,p.desc);

        fread(&p,sizeof(Productos),1,archProd);
    }

    fclose(archProd);

    return 0;
}