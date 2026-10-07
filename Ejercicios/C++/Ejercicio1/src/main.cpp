/*
Ejercicio 1:
Hacer una clase que guarde números enteros aleatorios a través de un método y muestre los
10 mas grandes a través de otro. Utilice especificador de acceso private para los datos y public
para los métodos. En la impresión de resultados no se deben modificar los datos.
*/

#include <iostream>
#include "numeros.h"

int main (void)
{
    cNumeros c1;
    c1.Ingreso();
    c1.Imprimir();
    c1.Mayores();

    return 0;
}
