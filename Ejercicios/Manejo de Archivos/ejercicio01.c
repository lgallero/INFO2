// 1. Hacer un programa que cuente la cantidad de bytes que contiene un archivo de texto.

#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *fp;

    fp = fopen("ejercicio01.txt","r");
    if ( fp == NULL) {
        perror("Erorr abriendo archivo");
        return 1;
    }

    fclose(fp);
    return 0;
}
