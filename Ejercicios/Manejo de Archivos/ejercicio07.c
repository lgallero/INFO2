/*
7) Guardar la variable de entorno PATH en path.txt
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char *path;
    int i = 0;
    char separador;

    path = getenv("PATH");

    if (path == NULL)
    {
        printf("No se pudo leer la variable de entorno PATH.\n");
        return 1;
    }

    fp = fopen("path.txt", "w");
    if (fp == NULL)
    {
        perror("Error al crear path.txt");
        return 1;
    }

#ifdef _WIN32
    separador = ';';
#else
    separador = ':';
#endif

    while (path[i] != '\0')
    {
        if (path[i] == separador)
        {
            fputc('\n', fp);
        }
        else
        {
            fputc(path[i], fp);
        }

        i++;
    }

    fclose(fp);

    printf("Variable PATH guardada correctamente en path.txt\n");

    return 0;
}