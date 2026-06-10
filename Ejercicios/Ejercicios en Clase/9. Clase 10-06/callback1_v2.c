/*Hacemos un programa que elija entre dos enteros, la condicion de la eleccion
 * se hace en tiempo de ejecucion*/

#include <stdio.h>

int max (int, int);
int min (int, int);
int suma (int, int);
int distancia(int, int);
int aplicar (int (*) (int, int), int, int);

int main(void)
{
    int x = 10, y = 40, aux;
    aux = aplicar (max, x, y);
    printf ("Luego de aplicar max el resultado es %d\n", aux);
    aux = aplicar (min, x, y);
    printf ("Luego de aplicar min el resultado es %d\n", aux);
    aux = aplicar (suma, x, y);
    printf ("Luego de aplicar suma el resultado es %d\n", aux);
    aux = aplicar (distancia, x, y);
    printf ("Luego de aplicar distancia el resultado es %d\n", aux);
    return 0;
}

int max (int a, int b)
{
    return (a>b) ? a : b;
}

int min (int a, int b)
{
    return (a<b) ? a : b;
}

int suma (int a, int b)
{
    return a+b;
}

int distancia(int a, int b)
{
    int i = a - b;
    return (i >=0 ) ? i : -i;
}

int aplicar (int (*cmp) (int, int), int x, int y)
{
    return cmp (x, y);

}
