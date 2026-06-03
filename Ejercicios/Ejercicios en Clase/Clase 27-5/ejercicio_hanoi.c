#include <stdlib.h>
#include <stdio.h> 

void hanoi(int , char, char, char);

int main()
{
    int a;
    printf("\n Ingrese la cantidad de anillos: ");
    scanf("%d",&a);

    hanoi(a,A,B,C);
    return 0;
}

void hanoi(int n , char Origen, char Auxiliar, char Destino){

    if(n == 1){
        printf("\nMover de %c a %c",Origen,Destino);
        return;
    }
    hanoi()
}