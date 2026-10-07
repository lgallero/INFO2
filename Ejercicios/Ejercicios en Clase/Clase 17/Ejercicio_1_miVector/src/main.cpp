#include <iostream>
#include "miVector.h"

int main ()
{
    int tam {};
    std::cout << "Ingrese el tamano del vector: ";
    if (!(std::cin >> tam))
    {
        std::cout << "Debe ingresar un numero entero\n";
        return 1;
    }

    miVector obj1 (tam);

    // Cargamos el vector por teclado usando el setter del docente.
    for (int i = 0; i < obj1.getTam (); i++)
    {
        int valor {};
        std::cout << "Ingrese el valor de la posicion " << i << ": ";
        if (!(std::cin >> valor))
        {
            std::cout << "Debe ingresar un numero entero\n";
            return 1;
        }
        obj1.setValor (valor, i);
    }

    std::cout << "\nVector cargado: ";
    for (int i = 0; i < obj1.getTam (); i++)
        std::cout << obj1.getValor (i) << ' ';
    std::cout << '\n';

    // Estos metodos funcionan aunque el vector todavia no este ordenado.
    obj1.imprimirMaximo ();
    obj1.imprimirMinimo ();

    int valorBuscado {};
    std::cout << "\nIngrese el valor que desea buscar: ";
    if (!(std::cin >> valorBuscado))
    {
        std::cout << "Debe ingresar un numero entero\n";
        return 1;
    }

    int posicion = obj1.buscar (valorBuscado);
    if (posicion == -1)
        std::cout << "El valor no esta en el vector\n";
    else
        std::cout << "Primera aparicion en la posicion " << posicion << '\n';

    obj1.ordenar ();

    std::cout << "\nVector ordenado: ";
    for (int i = 0; i < obj1.getTam (); i++)
        std::cout << obj1.getValor (i) << ' ';
    std::cout << '\n';

    // Las posiciones pueden cambiar despues de ordenar.
    posicion = obj1.buscar (valorBuscado);
    if (posicion != -1)
        std::cout << "Primera aparicion luego de ordenar: " << posicion << '\n';

    return 0;                      // Se ejecuta automaticamente ~miVector().
}
