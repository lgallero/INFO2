#include <stdlib.h>
#include <stdio.h>

int doble ( int );
int cuadrado ( int );
int negativo ( int );

int combinar( int (*)(int) , int , int );

int main(void)
{
    int (*tabla[])(int) = {&doble,&cuadrado,&negativo};

    int x = 10;
    int y = 20;
    int sel;

    printf("\n INGRESE UNA OPCION: ");
    printf("\n\t [0] Suma entre el doble");
    printf("\n\t [1] Suma entre el cuadrado");
    printf("\n\t [2] Suma entre el negativo");
    printf("\n Seleccione: ");
    scanf("%d",&sel);

    if ( sel >= 0 && sel < 3)
        printf ("\n\n EL RESULTADO ES: %d",combinar(tabla[sel],x,y));
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





