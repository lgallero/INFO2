#include <iostream>
#include "numeros.h"
#define MAX 20

void cNumeros::Ingreso()
{
    std::cout << "INGRESE 20 VALORES ALEATORIOS: ";
    for(int i=0 ; i < MAX ; i++)
    {
        std::cout << i+1 << ": "<<'\n';
        std::cin >> vector[i];
    }
}

void cNumeros::Imprimir()
{
    std::cout << "\nLos numeros que se ingresaron son: ";
    for(int i = 0 ; i < MAX ; i++)
    {
        std::cout << "\n\t" << i+1 <<":"<< vector[i];
    }
}

void cNumeros::Mayores()
{
    std::cout << "\nLos numeros mayores a 10 son: ";
    int flag {};
    for( int i = 0 ; i < MAX ; i++)
    {
        if(vector[i] >= 10)
        {
            flag = 1;
            std::cout << "\n\t" << i+1 << vector[i];
        }
    }

    if(flag){
        std::cout << "\n\t NO EXISTEN";
    }
}
