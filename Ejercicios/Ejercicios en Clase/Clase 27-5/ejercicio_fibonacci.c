#include <stdlib.h>
#include <stdio.h>

int fb (int);

int main()
{
    int a;
    printf("\n Ingrese el termino de fibonacci que quiera saber [0] para salir: ");
    scanf("%d",&a);

    while (a)
    {
        if(a<0)
        {
            printf("\nNumero invalido");
        }
        else
        {
            printf("\n El termino %d de fibonacci es: %d",a,fb(a-1));
        }

        printf("\n Ingrese el termino de fibonacci que quiera saber [0] para salir: ");
        scanf("%d",&a);
    }
    
    return 0;

}

int fb (int i)
{
    if(i == 0){
        return 0;
    }
    else if(i == 1){
        return 1;
    }
    else
    {
        return fb(i-1)+fb(i-2);
    }
}