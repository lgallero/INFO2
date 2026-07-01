/* main.c -- punto de entrada del TP1 "Archivos cruzados".
 *
 * Esto es lo minimo para que 'make' compile y enlace desde el dia cero.
 * Borra este mensaje y arma el programa a tu manera: los structs estan en
 * include/tp1.h y la consigna (los 3 puntos) en el README. Podes agregar
 * todos los .c que quieras dentro de src/.
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

int main(void)
{
    printf("TP1 - Archivos cruzados. Completa el programa (ver README).\n");
    printf("\n\n");

    struct movie *peliculas = NULL;
    int cantPeliculas = 0;

    // -------------------------------------------------------------------------
    printf("========== PUNTO 1 ==========\n");

    peliculas = leerPeliculas("data/movies1.dat", &cantPeliculas);
    if (peliculas == NULL) {
        printf("Error al leer movies1.dat\n");
        return 1;
    }

    Punto1(peliculas, cantPeliculas, "data/ratings1.dat");

    // -------------------------------------------------------------------------
    printf("\n========== PUNTO 2 ==========\n");

    Punto2 ("data/movies1.dat", "data/movies2.csv", "data/movies_final.dat");

    peliculas = leerPeliculas("data/movies_final.dat", &cantPeliculas);
    if (peliculas == NULL) {
        printf("Error al leer movies_final.dat\n");
        return 1;
    }

    Punto1(peliculas, cantPeliculas, "data/ratings1.dat");

    // -------------------------------------------------------------------------
    printf("\n========== PUNTO 3 ==========\n");

    Punto3 (peliculas, cantPeliculas, "data/ratings1.dat");

    // -------------------------------------------------------------------------
    free(peliculas);
    return 0;
}
