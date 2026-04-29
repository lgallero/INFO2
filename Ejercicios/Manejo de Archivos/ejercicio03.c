/* 
3) Concatenar dos archivos de texto ( poner al final de un archivoA el archivoB)
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *destino;
    FILE *origen;
    int c;

    if (argc != 3) // programa + archivo A + archivo B
    {
        printf("Uso: %s archivo_destino.txt archivo_a_agregar.txt\n", argv[0]);
        return 1;
    }

    destino = fopen(argv[1], "ab"); // como apend para poner al final
    if (destino == NULL)
    {
        perror("Error al abrir el archivo destino");
        return 1;
    }

    origen = fopen(argv[2], "rb"); // como lectura para leer el archivo
    if (origen == NULL)
    {
        perror("Error al abrir el archivo origen");
        fclose(destino);
        return 1;
    }

    while ((c = fgetc(origen)) != EOF) // Leo desde el origen
    {
        fputc(c, destino); // Lo pongo en mi destino
    }

    fclose(origen);
    fclose(destino);

    printf("Archivos concatenados correctamente.\n");



    return 0;
}