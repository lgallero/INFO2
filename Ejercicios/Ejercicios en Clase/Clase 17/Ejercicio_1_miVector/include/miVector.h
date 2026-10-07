#ifndef MIVECTOR_H
#define MIVECTOR_H

class miVector
{
private:
    int* m_vector {nullptr};
    int m_tam;

public:
    miVector (int tam);
    ~miVector ();
    void setValor (int valor, int pos);
    int getValor (int pos);
    int getTam (void);

    // Metodos pedidos en el ejercicio 1.
    void ordenar ();
    int buscar (int valor);
    void imprimirMaximo ();
    void imprimirMinimo ();
};

#endif
