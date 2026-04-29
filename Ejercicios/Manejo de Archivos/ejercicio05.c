/*
5) Mostrar el contenido de un archivo de texto
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;

    if (argc != 2) // programa + archivo
    {
        printf("Uso: %s archivo.txt\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    fclose(fp);

    return 0;
}
