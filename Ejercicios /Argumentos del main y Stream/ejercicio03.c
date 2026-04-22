// 3. Realizar un programa que muestre todas las variables de "environment" del sistema.

#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    int i = 0;

    while (envp[i] != NULL) { // Muentro todos las variables del entorno hasta encontrar el vector NULL
        printf("%s\n", envp[i]);
        i++;
    }

    return 0;
}