/* 
4) Buscar una palabra en un archivo y contar cuántas veces aparece
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char palabra_buscada[100];
    char palabra_leida[100];
    int contador = 0;

    if (argc != 3) // programa + archivo + palabra
    {
        printf("Uso: %s archivo.txt palabra\n", argv[0]);
        return 1;
    }

    strcpy(palabra_buscada, argv[2]); // Me guardo la palabra

    fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    while (fscanf(fp, "%99s", palabra_leida) == 1)
    {
        if (strcmp(palabra_leida, palabra_buscada) == 0)
        {
            contador++;
        }
    }

    fclose(fp);

    printf("La palabra \"%s\" aparece %d veces.\n", palabra_buscada, contador);

    return 0;
}