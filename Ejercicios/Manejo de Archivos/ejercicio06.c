/*
 6) Copiar un archivo a otro
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *origen;
    FILE *destino;
    int c;

    if (argc != 3)// programa + archivoOriginal +archivoCopia
    {
        printf("Uso: %s archivo_original.txt archivo_copia.txt\n", argv[0]);
        return 1;
    }

    origen = fopen(argv[1], "rb");
    if (origen == NULL)
    {
        perror("Error al abrir el archivo original");
        return 1;
    }

    destino = fopen(argv[2], "wb");
    if (destino == NULL)
    {
        perror("Error al crear el archivo copia");
        fclose(origen);
        return 1;
    }

    while ((c = fgetc(origen)) != EOF)
    {
        fputc(c, destino);
    }

    fclose(origen);
    fclose(destino);

    printf("Archivo copiado correctamente.\n");

    return 0;
}