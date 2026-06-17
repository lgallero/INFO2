#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int codigo;
    int cant_ventas;
} Ventas;

typedef struct {
    int codigo;
    float precio;
    char descripcion[51];
    int cant_ventas;
} Productos;

FILE * fb ( int , FILE*);

int main()
{
    Ventas v;
    Productos p;

    int tam_prod, tam_vent;

    FILE *pos;

    FILE *fp = fopen("productos.dat","r+b");
    if(!fp){
        perror("\n\n Error de apertura de archivo\n\n");
        exit(1);
    }

    FILE *fv = fopen("ventas.dat","rb");
    if(!fv){
        perror("\n\n Error de apertura de archivo\n\n");
        exit(1);
    }

    fseek(fp,0,SEEK_END);
    tam_prod = ftell(fp)/sizeof(Productos);
    printf("\n Cant de Prod: %d",tam_prod);
    rewind(fp);

    fseek(fv,0,SEEK_END);
    tam_vent = ftell(fv)/sizeof(Ventas);
    printf("\n Cant de Ventas: %d",tam_vent);
    rewind(fv);
    printf("\n\n");

    while(fread(&v, sizeof(Ventas), 1, fv) == 1){
        pos = fb(v.codigo,fp);
        if (pos != NULL){
            fp = pos;
            fread(&p, sizeof(Productos), 1 , fp);
            p.cant_ventas += v.cant_ventas;
            fseek(fp, -sizeof(Productos) , SEEK_CUR);
            fwrite(&p, sizeof(Productos), 1 , fp);
        }
        rewind(fp);
    }

    printf("\n\n FIN DEL PROGRAMA \n\n");
    fclose(fv);
    fclose(fp);
    return 0;
}

FILE * fb(int codigo, FILE *fp){
    Productos P;
    while(fread(&P,sizeof(Productos),1,fp)==1)
    {
        if(P.codigo == codigo)
        {
            fseek(fp, -sizeof(Productos) , SEEK_CUR);
            return fp;
        }
    }
    return NULL;
}