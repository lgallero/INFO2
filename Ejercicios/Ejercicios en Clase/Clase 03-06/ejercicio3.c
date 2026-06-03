/*
Ejercicio 3
Se dispone del archivo productos.dat que contiene la información de los productos, y cada registro se compone de la siguiente manera:
    • Código (entero)
    • Precio (float)
    • Descripción (de hasta 50 caracteres) 

    1. A partir de los registros que contiene el archivo productos.dat, crear un vector y guardar la información del archivo en memoria. La cantidad de registros se debe obtener en el programa.
    2. Realizar el procedimiento necesario en cuanto a la manipulación de memoria para: 
        a. El caso que el usuario quiere eliminar un producto. 
        b. El caso que el usuario quiere agregar un producto.
    3. Informar los productos que tienen precio mayor a 100.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int codigo;
    float precio;
    char descripcion[51];

} Producto;


void MostrarVector(Producto [], int);
void AgregarProducto(Producto**,int *);
void EliminarProducto(Producto**,int *);
void PreciosMayores(Producto [],int);

int main(){

FILE *FP; 
int tam,cant;
Producto *vector;
FP = fopen("Productos.dat","rb");
if(FP == NULL){
    printf("\nError apertura de archivo\n");
    return 1;
}

fseek(FP,0,SEEK_END);
tam = ftell(FP);
rewind(FP);
cant = tam/ sizeof(Producto);

printf("\n\n Cantidad de productos: %d\n\n",cant);

vector = (Producto*) malloc(cant*sizeof(Producto));
if(vector == NULL){
    printf("\n\nErorr, No se pudo reservar en memoria\n");
    return 1;
}

fread(vector, sizeof(Producto), cant, FP);

fclose(FP);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MostrarVector(vector,cant);

int a;
printf("\n\n\t\tMENU:");
printf("\n[1]: Agregar Producto");
printf("\n[2]: Eliminar Producto");
printf("\n[3]: Mostrar Productos");
printf("\n[4]: Productos mayores a 100$");
printf("\n[0]: Salir\t");
scanf("%d",&a);
while(a){
    switch (a)
    {
    case 1:
        AgregarProducto(&vector,&cant);
        break;

    case 2:
        EliminarProducto(&vector,&cant);
        break;

    case 3:
        MostrarVector(vector,cant);
        break;

    case 4:
        PreciosMayores(vector,cant);
        break;
        
    default:
        break;
    }

printf("\n\n\t\tMENU:");
printf("\n[1]: Agregar Producto");
printf("\n[2]: Eliminar Producto");
printf("\n[3]: Mostrar Productos");
printf("\n[4]: Productos mayores a 100$");
printf("\n[0]: Salir\t");
scanf("%d",&a);
}

printf("\n\nFIN DEL PROGRAMA\n\n");
free(vector);
return 0;
}



void MostrarVector(Producto vec[], int cant){

    printf("\n|%10s|%10s|%10s|%50s|","Producto","Codigo","Precio","Descripcion");
    for(int i = 0 ; i < cant ; i++){
        printf("\n|%10d|%10d|%10.2f|%50s|",i+1,vec[i].codigo,vec[i].precio,vec[i].descripcion);
    }
    printf("\n\n");
}

void AgregarProducto(Producto** vec, int *cant){
    Producto *aux;

    /* Agrandar el vector para un producto mas */
    aux = realloc(*vec, (*cant + 1) * sizeof(Producto));

    if(aux == NULL)
    {
        printf("\nError, no se pudo agrandar la memoria.\n");
        return;
    }

    /*
        Actualizar el puntero original del main.
        A partir de aca ya existe una nueva posicion.
    */
    *vec = aux;

    printf("\nIngrese los datos del nuevo producto:");

    printf("\nCodigo: ");
    scanf("%d", &(*vec)[*cant].codigo);

    printf("Precio: ");
    scanf("%f", &(*vec)[*cant].precio);

    printf("Descripcion: ");
    scanf(" %50[^\n]", (*vec)[*cant].descripcion);

    /* Aumentar la cantidad de productos */
    (*cant)++;

    printf("\nProducto agregado correctamente.\n");
}

void EliminarProducto(Producto **vec, int *cant)
{
    int codigoBuscado;
    int posicion = -1;
    Producto *aux;

    if(*cant == 0)
    {
        printf("\nNo hay productos para eliminar.\n");
        return;
    }

    printf("\nIngrese el codigo del producto que desea eliminar: ");
    scanf("%d", &codigoBuscado);

    /* Buscar la posicion del producto */
    for(int i = 0; i < *cant; i++)
    {
        if((*vec)[i].codigo == codigoBuscado)
        {
            posicion = i;
            break;
        }
    }

    if(posicion == -1)
    {
        printf("\nNo se encontro un producto con ese codigo.\n");
        return;
    }

    /*
        Desplazar hacia la izquierda los productos
        que estan despues del producto eliminado.
    */
    for(int i = posicion; i < *cant - 1; i++)
    {
        (*vec)[i] = (*vec)[i + 1];
    }

    /* Reducir la cantidad de productos */
    (*cant)--;

    /*
        Si se elimino el ultimo producto que quedaba,
        se libera toda la memoria.
    */
    if(*cant == 0)
    {
        free(*vec);
        *vec = NULL;

        printf("\nProducto eliminado correctamente.\n");
        return;
    }

    /* Achicar el vector dinamico */
    aux = realloc(*vec, (*cant) * sizeof(Producto));

    if(aux != NULL)
    {
        *vec = aux;
    }

    printf("\nProducto eliminado correctamente.\n");
}


void PreciosMayores(Producto vec[],int cant){
    int flag = 0; 
    for(int i = 0 ; i < cant ; i++ ){
        if(vec[i].precio > 100){
            printf("\n|%10d|%10d|%10.2f|%50s|",i+1,vec[i].codigo,vec[i].precio,vec[i].descripcion);
            flag = 1;
        }        
    }
    if(!flag){
        printf("\n No hay Profuctos que sean mayores a 100\n\n");
    }
}

