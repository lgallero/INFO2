/*
Ejercicio 2
    1. A partir de un valor entero que se ingresa por teclado reservar espacio de memoria para un tipo de dato int.
    2. Cargar el vector con valores enteros hasta que se ingresa el valor cero o negativo.
    3. Mostrar los datos ingresados.
    4. Indicar las posiciones que no tienen almacenados valores enteros.
*/
#include <stdlib.h>
#include <stdio.h>

void CargarVector(int ,int[]);
void MostrarVector(int ,int[]);
void ValoresSinValor(int ,int[]);

int main()
{
    // Punto 1) Ingresar por teclado el valor del vector y asignarle memoria
    int *vector, a;
    printf("\n Ingrese el tamanio del vector: ");
    scanf("%d",&a);

    vector = (int*) calloc(a,sizeof(int));
    if(vector == NULL){
        printf("\n Error, no se pudo reservar en memoria\n");
        return 1;
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    // Punto 2) Cargar Vector y se corta con 0 o numero negativo
    CargarVector(a,vector);

    // Punto 3) Mostrar Vector
    MostrarVector(a,vector);

    //Punto 4) Ver si hay valores sin cargar
    ValoresSinValor(a,vector);


    printf("\n\n");
    free(vector);
    return 0;
}

void CargarVector(int tam, int vec[])
{
    printf("\n\n Cargue el vector (con valores menores a 1 se corta la carga):");
    int a; 
    printf("\n Ingrese %d valores: ",tam);
    for(int i = 0 ; i < tam ; i++ ){
        printf("\n\t[%d] = ",i);
        scanf("%d",&a);
        if(a <= 0){
            break;
        }
        vec[i] = a;
    }
}

void MostrarVector(int tam ,int vec[]){
    printf("\n\nEl vector esta cargado con: ");
    for(int i = 0; i < tam ; i++){
        printf("\n\t[%d] = %d", i , vec[i]);
    }
}

void ValoresSinValor(int tam, int vec[]){

    printf("\n\nLas posiciones sin valores son: ");
    int flag = 0;

    for(int i=0 ; i < tam ; i++){
        if(vec[i] == 0){
            printf("\n [%d]", i);
            flag = 1;
        }
    }

    if (!flag){
        printf("NO HAY");
    }
}

