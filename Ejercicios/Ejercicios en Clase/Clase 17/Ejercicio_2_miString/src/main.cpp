#include <iostream>
#include "miString.h"

int main ()
{
    // El constructor mide la cadena y reserva exactamente lo necesario.
    miString obj1 ("Hola");

    std::cout << "Cadena inicial: ";
    obj1.imprimir ();
    std::cout << "Longitud: " << obj1.getLongitud () << '\n';

    obj1.agregar (" mundo");
    std::cout << "\nLuego de agregar texto: ";
    obj1.imprimir ();
    std::cout << "Longitud: " << obj1.getLongitud () << '\n';

    obj1.cargar ("Clase 17");
    std::cout << "\nLuego de cargar otra cadena: ";
    obj1.imprimir ();
    std::cout << "Longitud: " << obj1.getLongitud () << '\n';

    obj1.agregar (" - memoria dinamica");
    std::cout << "\nLuego de agregar otra vez: ";
    obj1.imprimir ();
    std::cout << "Longitud: " << obj1.getLongitud () << '\n';

    // Una cadena vacia necesita un solo lugar: el del terminador '\0'.
    obj1.cargar ("");
    std::cout << "\nCadena vacia: ";
    obj1.imprimir ();
    std::cout << "Longitud: " << obj1.getLongitud () << '\n';

    obj1.agregar ("Otra vez");
    std::cout << "\nTexto agregado a la cadena vacia: ";
    obj1.imprimir ();
    std::cout << "Longitud: " << obj1.getLongitud () << '\n';

    return 0;                      // Se ejecuta automaticamente ~miString().
}
