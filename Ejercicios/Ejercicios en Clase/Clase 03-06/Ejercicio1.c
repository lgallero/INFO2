/*
    Ejercicio 1
        1. A partir de un valor entero ingresado como argumento en el main() reservar espacio de memoria para un tipo de dato float.
        2. Cargar el vector con valores float que se ingresan por teclado.
        3. Mostrar los datos ingresados.
        4. Calcular y mostrar el promedio.
        5. Mostrar la posición y el contenido de aquellos valores mayores a 20.
*/

#include <stdlib.h>
#include <stdio.h>

float Promedio (int, float[]);

int main(int argc, char *argv[])
{
    // Punto a) Resevar en memoria ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(argc < 2){
        printf("\nINGRESE NUMERO DE VECTOR DESDE ARGUMENTO\n");
        return 1;
    }
    int reservado = atoi(argv[1]);

    if(reservado <= 0){
        printf("\n Numero invalido");
        return 1;
    }

    printf("\n Numero reservado: %d\n\n",reservado);

    float *vector = (float*) malloc( reservado * sizeof(float));
    if(vector == NULL){
        printf("\n Error, no se pudo reservar en memoria\n");
        return 1;
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Punto b) Cargar el vector por teclado
    float a;
    for(int i = 0; i < reservado ; i++){
        printf("\nIngrese %d° numero flotante: ",i+1);
        scanf("%f",&a);
        vector[i] = a;
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    // Punto c) Mostrar los valores ingresados ~~~~~~~~~~~~~~~~~~~~~~
    printf("\n\n\nLos datos ingresados son: ");
    for(int i = 0; i < reservado ; i++){
        printf("\n[%d] = %.2f",i,vector[i]);
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    //Punto d) Calcular el primedio y mostrarlo ~~~~~~~~~~~~~~~~~~~~~
    float Prom = Promedio(reservado, vector);
    printf("\n\n El Promedio es: %.2f", Prom);
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    //Punto e) Mostrar la posicion y el valor de los que son mayores a 20
    int flag = 0;
    printf("\nValores mayores a 20: ");
    for(int i=0 ; i < reservado ; i++){
        if(vector[i] > 20)
        {
            flag = 1;
            printf("\nvec[%d] = %.2f",i,vector[i]);
        }
    }
    if(!flag)
    {
        printf("\n No hay valores mayores a 20");
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    printf("\n\n");
    free(vector);
    return 0;
}

float Promedio (int tam, float vec[]){
    float suma=0;
    for(int i=0 ; i<tam ;i++){
        suma += vec[i];
    }
    return suma/(float)tam;
}