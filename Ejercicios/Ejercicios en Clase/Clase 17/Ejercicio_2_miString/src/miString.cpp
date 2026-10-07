#include "miString.h"
#include <iostream>

miString::miString (const char* cadena)
{
    // Contamos caracteres hasta el terminador. El '\0' no cuenta.
    m_longitud = 0;
    while (cadena[m_longitud] != '\0')
        m_longitud++;

    // Reservamos un lugar extra para guardar el '\0'.
    m_cadena = new char [m_longitud + 1];

    // Con <= tambien copiamos el terminador de la cadena.
    for (int i = 0; i <= m_longitud; i++)
        m_cadena[i] = cadena[i];
}

miString::~miString ()
{
    delete[] m_cadena;
}

void miString::cargar (const char* cadena)
{
    int nuevaLongitud = 0;
    while (cadena[nuevaLongitud] != '\0')
        nuevaLongitud++;

    char* nuevaCadena = new char [nuevaLongitud + 1];

    for (int i = 0; i <= nuevaLongitud; i++)
        nuevaCadena[i] = cadena[i];

    // Reemplazamos el bloque anterior por el que acabamos de cargar.
    delete[] m_cadena;
    m_cadena = nuevaCadena;
    m_longitud = nuevaLongitud;
}

void miString::imprimir ()
{
    std::cout << m_cadena << '\n';
}

int miString::getLongitud (void)
{
    return m_longitud;
}

void miString::agregar (const char* texto)
{
    int longitudTexto = 0;
    while (texto[longitudTexto] != '\0')
        longitudTexto++;

    int nuevaLongitud = m_longitud + longitudTexto;
    char* nuevaCadena = new char [nuevaLongitud + 1];

    // Copiamos el texto viejo, sin su '\0'.
    for (int i = 0; i < m_longitud; i++)
        nuevaCadena[i] = m_cadena[i];

    // Pegamos lo nuevo a continuacion. Este bucle copia tambien el '\0'.
    for (int i = 0; i <= longitudTexto; i++)
        nuevaCadena[m_longitud + i] = texto[i];

    // Recien ahora podemos liberar el bloque que contenia el texto viejo.
    delete[] m_cadena;
    m_cadena = nuevaCadena;
    m_longitud = nuevaLongitud;
}
