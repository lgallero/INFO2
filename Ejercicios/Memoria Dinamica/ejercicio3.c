/*
Ejercicio 3:
Se tiene la siguiente declaración de registro:

 struct producto {
     int codigo;
     char descripcion[41];
     float precio;
 };
Definir un puntero de tipo producto y luego mediante la función malloc crear un registro en la pila dinámica.
 Cargar el registro, imprimirlo y finalmente liberar el espacio reservado mediante la función free.
*/

#include <stdio.h>
#include <stdlib.h>

struct producto {
    int codigo;
    char descripcion[41];
    float precio;
};

int main(void)
{
    struct producto *pProducto = NULL;

    if ((pProducto = malloc(sizeof(struct producto)) == NULL)){
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    printf("Ingrese el codigo del producto: ");
    scanf("%d", &pProducto->codigo);

    printf("Ingrese la descripcion del producto: ");
    scanf(" %40[^\n]", pProducto->descripcion);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &pProducto->precio);

    printf("\nDatos del producto:\n");
    printf("Codigo: %d\n", pProducto->codigo);
    printf("Descripcion: %s\n", pProducto->descripcion);
    printf("Precio: %.2f\n", pProducto->precio);

    free(pProducto);
    return 0;
}