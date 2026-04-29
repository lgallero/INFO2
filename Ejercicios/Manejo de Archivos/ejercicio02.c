/*
 Hacer un programa que compare 2 archivos de texto e indique si tienen o no igual contenido
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp1;
    FILE *fp2;
    int c1;
    int c2;
    int iguales = 1;

    if (argc != 3) //programa + archivo 1 + archivo 2
    {
        printf("Uso: %s archivo1.txt archivo2.txt\n", argv[0]);
        return 1;
    }

    fp1 = fopen(argv[1], "rb");
    if (fp1 == NULL)
    {
        perror("Error al abrir el primer archivo");
        return 1;
    }

    fp2 = fopen(argv[2], "rb");
    if (fp2 == NULL)
    {
        perror("Error al abrir el segundo archivo");
        fclose(fp1);
        return 1;
    }

    while (iguales)
    {
        c1 = fgetc(fp1);
        c2 = fgetc(fp2);

        if (c1 != c2)
        {
            iguales = 0; // No son iguales
            break;
        }

        if (c1 == EOF && c2 == EOF) // ambos terminaron el archivo
        {
            break;
        }
    }

    fclose(fp1);
    fclose(fp2);

    if (iguales)
    {
        printf("Los archivos tienen igual contenido.\n");
    }
    else
    {
        printf("Los archivos NO tienen igual contenido.\n");
    }

    return 0;
}