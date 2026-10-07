#include "miVector.h"
#include <iostream>
#include <cstdlib>

miVector::miVector (int tam)
{
    if (tam <= 0)
    {
        // Como en el ejemplo del docente: exit termina el programa.
        std::cout << "El tamano debe ser mayor que cero\n";
        std::exit (0);
    }

    m_tam = tam;
    m_vector = new int [tam] {};     // Todos los elementos empiezan en cero.
}

miVector::~miVector ()
{
    delete[] m_vector;
}

void miVector::setValor (int valor, int pos)
{
    if (pos >= 0 && pos < m_tam)
        m_vector[pos] = valor;
    else
        std::cout << "Los parametros ingresados no son validos\n";
}

int miVector::getValor (int pos)
{
    if (pos >= 0 && pos < m_tam)
        return m_vector[pos];
    else
    {
        std::cout << "Los parametros ingresados no son validos\n";
        return 0;
    }
}

int miVector::getTam (void)
{
    return m_tam;
}

void miVector::ordenar ()
{
    // Burbujeo: comparamos dos vecinos e intercambiamos si estan al reves.
    for (int i = 0; i < m_tam - 1; i++)
    {
        for (int j = 0; j < m_tam - 1 - i; j++)
        {
            if (m_vector[j] > m_vector[j + 1])
            {
                int aux = m_vector[j];
                m_vector[j] = m_vector[j + 1];
                m_vector[j + 1] = aux;
            }
        }
    }
}

int miVector::buscar (int valor)
{
    for (int i = 0; i < m_tam; i++)
    {
        if (m_vector[i] == valor)
            return i;              // Salimos en la primera coincidencia.
    }

    return -1;                     // Terminamos de recorrer y no estaba.
}

void miVector::imprimirMaximo ()
{
    int maximo = m_vector[0];

    for (int i = 1; i < m_tam; i++)
    {
        if (m_vector[i] > maximo)
            maximo = m_vector[i];
    }

    std::cout << "Maximo: " << maximo << '\n';
}

void miVector::imprimirMinimo ()
{
    int minimo = m_vector[0];

    for (int i = 1; i < m_tam; i++)
    {
        if (m_vector[i] < minimo)
            minimo = m_vector[i];
    }

    std::cout << "Minimo: " << minimo << '\n';
}
