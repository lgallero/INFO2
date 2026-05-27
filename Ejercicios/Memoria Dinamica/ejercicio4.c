/*
Ejercicio 4:
Pedir ingresar por teclado cuantas letras tiene una palabra.
Seguidamente crear un vector en forma dinámica que reserve el espacio mínimo para ingresar dicha palabra.
Cargar por teclado la palabra, mostrarla y finalmente liberar el espacio requerido.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int cantidadLetras;
    char *palabra = NULL;

    printf("Ingrese cuantas letras tiene la palabra: ");
    scanf("%d", &cantidadLetras);

    if (cantidadLetras <= 0)
    {
        printf("La cantidad de letras debe ser mayor que cero.\n");
        return 1;
    }

    palabra = malloc((cantidadLetras + 1) * sizeof(char));

    if (palabra == NULL)
    {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    printf("Ingrese la palabra: ");
    scanf("%s", palabra);

    printf("\nLa palabra ingresada es: %s\n", palabra);

    free(palabra);
    palabra = NULL;

    return 0;
}