/*
Ejercicio 2:
Ingresar por teclado un entero que represente la cantidad de elementos que debe crearse un vector. 
Crear el vector en forma dinámica, cargar e imprimir sus datos. Hacer todo en main.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cantidad;
    int *vector = NULL;

    printf("Ingrese la cantidad de elementos del vector: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0)
    {
        printf("La cantidad debe ser mayor que cero.\n");
        return 1;
    }

    if ((vector = malloc(cantidad * sizeof(int))) == NULL)
    {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("\nElementos del vector:\n");

    for (int i = 0; i < cantidad; i++)
    {
        printf("vector[%d] = %d\n", i, vector[i]);
    }

    free(vector);
    return 0;
}