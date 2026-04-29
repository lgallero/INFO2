// 1. Hacer un programa que cuente la cantidad de bytes que contiene un archivo de texto.

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    long contador = 0;

    if (argc != 2) // Le tengo que pasar el nombre del archivo por consola
    {
        printf("Uso: %s archivo.txt\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb"); // Abro en modo Lectura-binario

    if (fp == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) // Como cada caracter es un byte, voy leyendo 1x1 hasta encontrar el fin del archivo
    {
        contador++;
    }

    fclose(fp);

    printf("El archivo contiene %ld bytes.\n", contador);

    return 0;
}