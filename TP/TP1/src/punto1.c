/*
Calcular la calificación promedio de cada género (promedio sobre todas las películas de Acción, Aventura, etc.). Imprimirlos en pantalla.
*/
#include <stdio.h>
#include "tp1.h"

void Punto1 (struct movie peliculas[], int cantPeliculas, const char *archivoRatings)
{
    FILE *FP;
    struct rating ratingActual;
    double sumaRatings[CANT_GENEROS] = {0};
    int cantidadRatings[CANT_GENEROS] = {0};
    int posPelicula;
    int i;

    FP = fopen(archivoRatings, "rb");
    if (FP == NULL) {
        printf("No se pudo abrir %s\n", archivoRatings);
        return;
    }

    while (fread(&ratingActual, sizeof(struct rating), 1, FP) == 1) {

        posPelicula = buscarPeliculaPorId (peliculas, cantPeliculas, ratingActual.idMovie);

        if (posPelicula != -1) 
        {
            for (i = 0; i < CANT_GENEROS; i++) {                    // Recorro cada genero
                if (perteneceAGenero(peliculas[posPelicula], i)) {  // Consulto si la pelicula coincide con el genero 
                    sumaRatings[i] += ratingActual.rating;          // Sumo el valor del ranting de la pelicula con ese genero
                    cantidadRatings[i]++;                           // Sumo que se hizo una reseña
                }
            }
        }
    }

    fclose(FP);

    printf("%-15s %-15s %-15s\n", "Genero", "Cantidad", "Promedio");
    printf("---------------------------------------------\n");

    for (i = 0; i < CANT_GENEROS; i++) {
        if (cantidadRatings[i] > 0) {
            printf ("%-15s %-15d %.2f\n", obtenerNombreGenero(i), cantidadRatings[i], sumaRatings[i] / cantidadRatings[i]);
        } else {
            printf ("%-15s %-15d Sin datos\n", obtenerNombreGenero(i), cantidadRatings[i]);
        }
    }
    printf("\n\n");
}