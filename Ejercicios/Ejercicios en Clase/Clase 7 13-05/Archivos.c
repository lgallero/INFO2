/*
1. Crear archivo binario "productos.dat" con la informacion de 10 productos.
La informacion debe contener:
    • Código (entero)
    • Precio (float)
    • Descripción (de hasta 50 caracteres)

2.Mostrar la información del archivo binario “productos.dat”

3. Realizar la lógica correcta para modificar en forma masiva los precios de todos los productos del
archivo “productos.dat” a partir de un porcentaje:
    a. Que se ingresa por teclado.
    b. Que se ingresa como argumentos en el main()

4. Realizar la lógica correcta para modificar el precio de un producto del archivo “productos.dat” que
es ingresado por teclado junto a su nuevo precio.

5. Realizar la lógica correcta para guardar la información del archivo “productos.dat” en un archivo
de texto llamado “productos.txt” aplicando el concepto de escribir con formato, utilizando como
separador de campo el carácter pipe (|).

6. Realizar la lógica correcta para mostrar la información del archivo “productos.txt”

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    float precio;
    char descripcion[51];
} Producto;

//Funciones
void crearArchivoBinario(void);
void mostrarArchivoBinario(void);
void modificarPorcentaje(int argc, char *argv[]);
void modificarPrecio(void);
void guardarArchivoTexto(void);
void mostrarArchivoTexto(void);

int main(int argc , char *argv[])
{
    int a;
    printf("Ingrese numero para realizar: \n\t [1] Crear Archivo binario \n\t [2] Ver archivo binario\n\t [3] Modificar precios por porcentaje\n\t [4] Modificar Precio \n\t [5] Guardar en .txt\n\t [6] Ver Archivo .txt\n\n\t [0] Salir\n\t");
    scanf("%d",&a);
    while(a){
        switch (a)
            {
            case 1:
                crearArchivoBinario();
                break;
            
            case 2:
                mostrarArchivoBinario();
                break;

            case 3:
                modificarPorcentaje(argc, argv);
                break;

            case 4:
                modificarPrecio();
                break;

            case 5:
                guardarArchivoTexto();
                break;
            
            case 6:
                mostrarArchivoTexto();
                break;

            default:
                printf("Opcion invalida.\n");
                break;
            }
    printf(" \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    printf("Ingrese numero para realizar: \n\t [1] Crear Archivo binario \n\t [2] Ver archivo binario\n\t [3] Modificar precios por porcentaje\n\t [4] Modificar Precio \n\t [5] Guardar en .txt\n\t [6] Ver Archivo .txt\n\n\t [0] Salir\n\t");
    scanf("%d",&a);
    printf(" \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    }
   
    return 0;
}


void crearArchivoBinario(){

    FILE *fp = fopen("productos.dat", "wb");
    if (!fp) {
        perror("No se pudo abrir el archivo");
        exit(1);
    }

    Producto p;

    for(int i=0 ; i<10 ;i++)
    {
        printf("\nProducto %d\n", i + 1);
        printf("\nIngrese descripcion del producto: ");
        scanf(" %50[^\n]", p.descripcion);
        printf("Ingrese codigo del producto: ");
        scanf("%d", &p.codigo);
        printf("Ingrese precio del producto: ");
        scanf("%f", &p.precio);

        fwrite(&p, sizeof(p), 1, fp);
    };
    fclose(fp);
    printf("\n ~~~ Archivo creado correctamente.~~~\n");
}

void mostrarArchivoBinario(){

    FILE *f = fopen("productos.dat", "rb");
    if (!f) {
        perror("Error al abrir el archivo");
        return;
    }

    Producto p;
    printf("----- Contenido del archivo -----\n");

    while (fread(&p, sizeof(Producto), 1, f) == 1) {
        printf("Codigo: %3d | Descripcion: %-50s | Precio: $%7.2f\n", p.codigo, p.descripcion, p.precio);
    }

    printf( "\n----------------------------------\n");

    fclose(f);

}

void modificarPorcentaje(int argc, char *argv[]){

    FILE *f = fopen("productos.dat", "r+b");
    if (!f) {
        perror("Error al abrir el archivo");
        return;
    }

    float porcentaje;

    // Si ingresaron por argunmento
    if (argc > 1) {
        char *fin;

        porcentaje = strtof(argv[1], &fin);
        if (*argv[1] == '\0' || *fin != '\0') {
            printf("El argumento '%s' no es un porcentaje valido.\n", argv[1]);
            fclose(f);
            return;
        }

        printf("Se usara el porcentaje recibido por argumento: %.2f%%\n", porcentaje);
    } else {
        printf("Ingrese el porcentaje a aplicar: ");
        if (scanf("%f", &porcentaje) != 1) {
            printf("No se pudo leer el porcentaje.\n");
            fclose(f);
            return;
        }
    }

    Producto p;

    while (fread(&p, sizeof(Producto), 1, f) == 1) {
        p.precio += p.precio * porcentaje / 100.0f;

        fseek(f, -(long) sizeof(Producto), SEEK_CUR);
        fwrite(&p, sizeof(Producto), 1, f);
    }

    fclose(f);
    printf("Precios actualizados correctamente.\n");
}

void modificarPrecio(){

    int a,tam,flag=0;;
    Producto p;

    FILE *fp = fopen("productos.dat", "r+b");
    if (!fp) {
        perror("No se pudo abrir el archivo");
        exit(1);
    }

    fseek(fp,0,SEEK_END);
    tam = ftell(fp)/sizeof(Producto);
    fseek(fp, 0, SEEK_SET);

    printf("\nIngrese codigo del producto: ");
    scanf("%d",&a);

    int i = 0;
    while(i < tam && !flag )
    {
        fseek(fp, i * sizeof(Producto), SEEK_SET);
        fread(&p,sizeof(Producto),1,fp);
        if (a == p.codigo)
        {
            printf("\nPrecio Actual %2.2f$\n Ingrese el nuevo precio: ", p.precio);
            scanf("%f", &p.precio);
            fseek(fp, i * sizeof(Producto), SEEK_SET);
            fwrite(&p,sizeof(Producto),1,fp);
            flag = 1;

        }
        i++;
    }

    if(!flag)
    {
        printf("\n  ~~~ CODIGO NO ENCONTRADO ~~~\n");
    }
    else
    {
        printf("\n $$$$$$$$$ PRECIO MODIFICADO $$$$$$$$$\n");
    }


    fclose(fp);
}

void guardarArchivoTexto(){

    FILE *fp = fopen("productos.dat", "rb");
    if(!fp){
        perror("No se pudo abrir el archivo binario");
        exit(1);
    }

    FILE *f = fopen("productos.txt", "w");
    if(!f){
        perror("No se pudo abrir el archivo texto");
        exit(1);
    }

    Producto p;

            fprintf(f, "|%-6s|%-50s|%10s|\n", "CODIGO", "DESCRIPCION", "PRECIO");

                while(fread(&p, sizeof(Producto), 1, fp) == 1)
                {
                    fprintf(f, "|%6d|%-50s|%10.2f|\n",
                            p.codigo,
                            p.descripcion,
                            p.precio);
                }

    fclose(fp);
    fclose(f);
    printf("\n ~~~ Archivo de Texto Creado ~~~ \n");
}

void mostrarArchivoTexto(){
    FILE *fp = fopen("productos.txt", "r");
    if(!fp){
        perror("No se pudo abrir el archivo texto");
        exit(1);
    }

    printf("\n ~~~ Contenido de Archivo.txt ~~~ \n");
    int c;
    while ((c = fgetc(fp)) != EOF) {
       putchar(c);
    }
    printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    fclose(fp);
}
