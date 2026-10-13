#include "matriz.h"

#include <iostream>

int **matriz::reservarMemoria(int filas, int columnas)
{
    int **datos = new int *[filas];

    for (int i = 0; i < filas; i++) {
        datos[i] = new int[columnas];
    }

    return datos;
}

void matriz::liberarMemoria(int **datos, int filas)
{
    if (datos == nullptr) {
        return;
    }

    for (int i = 0; i < filas; i++) {
        delete[] datos[i];
    }

    delete[] datos;
}

matriz::matriz(int filas, int columnas)
{
    m_filas = 0;
    m_columnas = 0;
    m_mat = nullptr;

    if (filas <= 0 || columnas <= 0) {
        std::cout << "Error: las filas y columnas deben ser mayores a cero.\n";
        return;
    }

    m_mat = reservarMemoria(filas, columnas);

    m_filas = filas;
    m_columnas = columnas;

    for (int i = 0; i < m_filas; i++) {
        for (int j = 0; j < m_columnas; j++) {
            if (m_filas == m_columnas && i == j) {
                m_mat[i][j] = 1;
            } else {
                m_mat[i][j] = 0;
            }
        }
    }

    std::cout << "Constructor: matriz de " << m_filas
              << " x " << m_columnas << '\n';
}

matriz::~matriz()
{
    liberarMemoria(m_mat, m_filas);
    std::cout << "Destructor: matriz de " << m_filas
              << " x " << m_columnas << '\n';
}

bool matriz::validarPosicion(int fila, int columna)
{
    if (fila < 0 || fila >= m_filas || columna < 0 || columna >= m_columnas) {
        std::cout << "Error: la fila o columna esta fuera de la matriz.\n";
        return false;
    }

    return true;
}

int matriz::getFilas()
{
    return m_filas;
}

int matriz::getColumnas()
{
    return m_columnas;
}

int matriz::getDatoEn(int fila, int columna)
{
    if (!validarPosicion(fila, columna)) {
        return 0;
    }
    return m_mat[fila][columna];
}

void matriz::setDato(int fila, int columna, int dato)
{
    if (!validarPosicion(fila, columna)) {
        return;
    }
    m_mat[fila][columna] = dato;
}

void matriz::printAll()
{
    for (int i = 0; i < m_filas; i++) {
        for (int j = 0; j < m_columnas; j++) {
            std::cout << m_mat[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

void matriz::setAll(int dato)
{
    for (int i = 0; i < m_filas; i++) {
        for (int j = 0; j < m_columnas; j++) {
            m_mat[i][j] = dato;
        }
    }
}

void matriz::transpose()
{
    if (m_mat == nullptr) {
        std::cout << "Error: la matriz no esta inicializada.\n";
        return;
    }

    int **traspuesta = reservarMemoria(m_columnas, m_filas);

    for (int i = 0; i < m_filas; i++) {
        for (int j = 0; j < m_columnas; j++) {
            traspuesta[j][i] = m_mat[i][j];
        }
    }

    liberarMemoria(m_mat, m_filas);
    m_mat = traspuesta;

    int filasAnteriores = m_filas;
    m_filas = m_columnas;
    m_columnas = filasAnteriores;
}

void matriz::addFila(int dato)
{
    if (m_mat == nullptr) {
        std::cout << "Error: la matriz no esta inicializada.\n";
        return;
    }

    int **nueva = reservarMemoria(m_filas + 1, m_columnas);

    for (int i = 0; i < m_filas; i++) {
        for (int j = 0; j < m_columnas; j++) {
            nueva[i][j] = m_mat[i][j];
        }
    }

    for (int j = 0; j < m_columnas; j++) {
        nueva[m_filas][j] = dato;
    }

    liberarMemoria(m_mat, m_filas);
    m_mat = nueva;
    m_filas++;
}

void matriz::addCol(int dato)
{
    if (m_mat == nullptr) {
        std::cout << "Error: la matriz no esta inicializada.\n";
        return;
    }

    int **nueva = reservarMemoria(m_filas, m_columnas + 1);

    for (int i = 0; i < m_filas; i++) {
        for (int j = 0; j < m_columnas; j++) {
            nueva[i][j] = m_mat[i][j];
        }
        nueva[i][m_columnas] = dato;
    }

    liberarMemoria(m_mat, m_filas);
    m_mat = nueva;
    m_columnas++;
}
