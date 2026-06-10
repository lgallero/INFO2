#include <stdio.h>

int suma (int a, int b)
{
    return a + b ;
}

int opuesto (int a)
{
    return -a;
}

int resta (int a , int b)
{
    return a - b; 
}

// Definicion del tipo de puntero a funcion que recibe dos int y devuelve int
typedef int (*opBinaria)(int, int);
// Definicion del tipo de puntero a funcion que recibe int y devuelve int
typedef int (*opUnaria) (int);

int main(void)
{
    opBinaria ejemploPtr1 = &suma;
    opUnaria ejemploPtr2 = &opuesto;

    int x, y, z;
    x=30;
    y=2*x;

    z = ejemploPtr1 (x,y);
    printf ("La suma es: %d\n", z);
    printf ("La suma de %d y %d es: %d \n",x,y,(*ejemploPtr1)(x,y));
    printf ("El opuesto es: %d\n", ejemploPtr2(z));

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ejemploPtr1 = &resta;
    printf("La resta de %d y %d es: %d",x,y,ejemploPtr1(x,y));


    // test
    //ejemploPtr1 = &opuesto;
    //printf("El opuesto es : %d",ejemploPtr1(x));

    getchar();
    return 0;
}
