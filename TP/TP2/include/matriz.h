#ifndef MATRIZ_H
#define MATRIZ_H

class matriz
{
private:
    int m_filas, m_columnas;
    int **m_mat;

    int **reservarMemoria(int filas, int columnas);
    void liberarMemoria(int **datos, int filas);
    bool validarPosicion(int fila, int columna);

public:
    matriz(int filas, int columnas);
    ~matriz();

    // Una copia directa compartiria la memoria y la liberaria dos veces.
    matriz(const matriz &) = delete;
    matriz &operator=(const matriz &) = delete;

    int getFilas();
    int getColumnas();
    int getDatoEn(int fila, int columna);
    void setDato(int fila, int columna, int dato);
    void printAll();
    void transpose();
    void setAll(int dato);
    void addFila(int dato);
    void addCol(int dato);
};

#endif
