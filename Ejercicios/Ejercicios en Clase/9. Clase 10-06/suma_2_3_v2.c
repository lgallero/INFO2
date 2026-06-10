#include <stdlib.h>
#include <stdio.h>

int doble ( int );
int cuadrado ( int );
int negativo ( int );

int combinar( int (*)(int) , int , int );
int producto( int (*)(int) , int , int );

int main(void)
{
    int (*tabla[])(int) = {&doble,&cuadrado,&negativo};

    int x = 10;
    int y = 20;
    int sel_1 , sel_2;

    printf("\n INGRESE UNA OPCION: ");
    printf("\n\t [0] Suma");
    printf("\n\t [1] Producto");
    printf("\n Seleccione: ");
    scanf("%d",&sel_1);

    printf("\n\n\n INGRESE UNA OPCION: ");
    printf("\n\t [0] doble");
    printf("\n\t [1] cuadrado");
    printf("\n\t [2] negativo");
    printf("\n Seleccione: ");
    scanf("%d",&sel_2);

    if ( sel_1 == 0 && sel_2 >= 0 && sel_2 < 3)
        printf ("\n\n EL RESULTADO ES: %d",combinar(tabla[sel_2],x,y));
    else if ( sel_1 == 1 && sel_2 >= 0 && sel_2 < 3)
        printf ("\n\n EL RESULTADO ES: %d",producto(tabla[sel_2],x,y));
    else
        printf("\n\n ERROR, numero invalido!");
        
    getchar();
    printf ("\n\n");
    return 0;
}

int combinar( int (*pf)(int) , int x  , int y )
{
    return pf(x) + pf(y);
}
int producto( int (*pf)(int) , int x  , int y )
{
    return pf(x) * pf(y);
}

int doble ( int a)
{
    return 2*a;
}

int cuadrado ( int a )
{
    return a * a;
}

int negativo ( int a )
{
    return -a;
}





