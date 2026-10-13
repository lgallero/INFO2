#include "matriz.h"

#include <iostream>

int main()
{
    std::cout << "--- Objeto en el stack ---\n";
    {
        matriz m1(3, 3);
        std::cout << "Matriz identidad:\n";
        m1.printAll();

        std::cout << "Filas: " << m1.getFilas()
                  << ", columnas: " << m1.getColumnas() << '\n';

        m1.setDato(0, 1, 5);
        std::cout << "Dato en (0, 1): " << m1.getDatoEn(0, 1) << '\n';
        m1.printAll();

        std::cout << "Traspuesta:\n";
        m1.transpose();
        m1.printAll();

        std::cout << "Todos los elementos en 2:\n";
        m1.setAll(2);
        m1.printAll();

        std::cout << "Nueva fila con 7:\n";
        m1.addFila(7);
        m1.printAll();

        std::cout << "Nueva columna con 8:\n";
        m1.addCol(8);
        m1.printAll();

        std::cout << "Al salir de este bloque se destruye m1.\n";
    }

    std::cout << "\n--- Matriz rectangular ---\n";
    {
        matriz rectangular(2, 3);
        std::cout << "Matriz inicial en cero:\n";
        rectangular.printAll();

        int dato = 1;
        for (int i = 0; i < rectangular.getFilas(); i++) {
            for (int j = 0; j < rectangular.getColumnas(); j++) {
                rectangular.setDato(i, j, dato);
                dato++;
            }
        }

        std::cout << "Matriz con datos:\n";
        rectangular.printAll();
        rectangular.transpose();
        std::cout << "Traspuesta de 3 x 2:\n";
        rectangular.printAll();
    }

    std::cout << "\n--- Objeto en el heap ---\n";
    matriz *m2 = new matriz(4, 4);
    m2->printAll();
    std::cout << "delete ejecuta el destructor de m2.\n";
    delete m2;

    std::cout << "\n--- Errores de dimensiones e indices ---\n";
    matriz invalida(0, 3);

    matriz pequena(1, 1);
    pequena.setDato(1, 0, 9);
    pequena.getDatoEn(0, -1);

    return 0;
}
