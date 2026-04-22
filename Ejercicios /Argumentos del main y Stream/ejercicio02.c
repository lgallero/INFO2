/* 2. Realizar un programa que reciba un único argumento desde la línea de comandos. 
Si el argumento es un número entero válido y positivo, imprimirlo por stdout. 
Si el argumento no es válido o es negativo, imprimir un mensaje de error por stderr. 
Redirigir el resultado desde el Shell a un archivo "resultado.txt".
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
   char *fin;
   int valor;

   // Chequeo de argumentos 
   if ( argc != 2){ // nombre + unico argumento = 2 
   
    fprintf(stderr, "Error: se debe pasar un unico argumento.\n");
    return 1;
   }

   valor = strtol(argv[1], &fin, 10);

   //Si es una letra
    if (*fin != '\0') {
        fprintf(stderr, "Error: '%s' no es un entero valido.\n", argv[1]);
        return 1;
    }

    //Si es un numero negativo
        if (valor < 0) {
        fprintf(stderr, "Error: el numero no puede ser negativo.\n");
        return 1;
    }

    printf("Numero valido y positivo: %d\n", valor);
    return 0;
}