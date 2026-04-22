// 1. Realizar un programa que muestre la cantidad de argumentos del main que recibe y los enumere

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Cantidad de argumentos recibidos: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}