/*Realizar un programa que funcione como una calculadora por argumentos del main. 
Así: "calc operacion numero1 numero2 ...""
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *fin;
    double resultado, num;

    if (argc < 4) { // nombre + operacion + num 1 + num 2 = 4 (como minimo)
        printf("Uso: %s operacion numero1 numero2 [numero3 ...]\n", argv[0]);
        printf("Operaciones: sumar, restar, multiplicar, dividir\n");
        return 1;
    }

    resultado = strtod(argv[2], &fin); // tomo el primer numero y me fijo si es valido 
    if (*fin != '\0') {
        fprintf(stderr, "Error: '%s' no es un numero valido.\n", argv[2]);
        return 1;
    }

    for (int i = 3; i < argc; i++) { // arrnaco del 3ro que es el num 2 y me fijo si es valido
        num = strtod(argv[i], &fin);
        if (*fin != '\0') {
            fprintf(stderr, "Error: '%s' no es un numero valido.\n", argv[i]);
            return 1;
        }

        if (strcmp(argv[1], "sumar") == 0) {
            resultado += num;
        } 
        else if (strcmp(argv[1], "restar") == 0) {
            resultado -= num;
        } 
        else if (strcmp(argv[1], "multiplicar") == 0) {
            resultado *= num;
        } 
        else if (strcmp(argv[1], "dividir") == 0) {
            if (num == 0) {
                fprintf(stderr, "Error: division por cero.\n");
                return 1;
            }
            resultado /= num;
        } 
        else {
            fprintf(stderr, "Error: operacion no valida.\n");
            return 1;
        }
    }

    printf("Resultado: %.2f\n", resultado);
    return 0;
}