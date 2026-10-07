#ifndef MISTRING_H
#define MISTRING_H

class miString
{
private:
    char* m_cadena {nullptr};
    int m_longitud;

public:
    miString (const char* cadena);
    ~miString ();
    void cargar (const char* cadena);
    void imprimir ();
    int getLongitud (void);
    void agregar (const char* texto);
};

#endif
