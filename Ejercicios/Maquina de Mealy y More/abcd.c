#include <stdlib.h>
#include <stdio.h>

typedef enum{
    A,
    B,
    C,
    D
} Estados;


int main()
{
    Estados Estado = A;
    char c;
    c = getchar();

    while ( c != EOF)
    {
        if(c != '\n')
        {
            switch (Estado)
            {
            case A:
                if(c == 'a')
                {
                    Estado = B;
                }
                else{
                    printf("Secuencia Invalida...\n\n");
                }
                break;
            
            case B:
                if(c == 'b')
                {
                    Estado = C;
                }
                else if( c == 'a' )
                {
                    printf("Secuencia Invalida...\n\n");
                }
                else if (c != 'a' && c != 'b'){
                    printf("Secuencia Invalida...\n\n");
                    Estado = A;
                }
                break;
            
            case C:
                if(c == 'c')
                {
                    Estado = D;
                }
                else if( c == 'a' )
                {
                    printf("Secuencia Invalida...\n\n");
                    Estado = B;
                }
                else if (c != 'a' && c != 'c'){
                    printf("Secuencia Invalida...\n\n");
                    Estado = A;
                }              
                break;

            case D:
                if(c == 'd')
                {
                    Estado = A;
                    printf("Secuencia Correcta!!!\n\n");
                }
                else if( c == 'a' )
                {
                    printf("Secuencia Invalida...\n\n");
                    Estado = B;
                }
                else if (c != 'a' && c != 'd'){
                    printf("Secuencia Invalida...\n\n");
                    Estado = A;
                }
                break;
            }
        }
        
        c = getchar();
    }
    return 0;
}