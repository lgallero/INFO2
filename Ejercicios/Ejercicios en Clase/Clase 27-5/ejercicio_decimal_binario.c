#include <stdlib.h>
#include <stdio.h>

void bin(int);

int main()
{
    int a;
    printf("\nINGRESE NUMERO: ");
    scanf("%d",&a);
    printf("\nEl numero %d en binario es: ",a);
    bin(a);

    return 0;
}

void bin(int n)
{
    int RESULTADO, RESTO;
    if(n == 0){
        return;
    }
    else{
        RESULTADO = n/2;
        RESTO = n%2;
        bin(RESULTADO);
        printf("%d",RESTO);
    }
}