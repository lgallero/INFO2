#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

// Leer el contenido de archivo y generar un vector dinamico
struct movie *leerPeliculas(const char *nombreArchivo, int *cantidad)
{
    FILE *FP;
    struct movie *peliculas;
    long tam_Archivo;
    int cant;

    FP = fopen(nombreArchivo, "rb");

    if (FP == NULL) {
        printf("No se pudo abrir %s\n", nombreArchivo);
        *cantidad = 0;
        return NULL;
    }

    fseek(FP, 0, SEEK_END);
    tam_Archivo = ftell(FP);
    rewind(FP);

    cant = tam_Archivo / sizeof(struct movie);

    peliculas = malloc(cant * sizeof(struct movie));

    if (peliculas == NULL) {
        printf("No se pudo reservar memoria\n");
        fclose(FP);
        *cantidad = 0;
        return NULL;
    }

    fread(peliculas, sizeof(struct movie), cant, FP);

    fclose(FP);

    *cantidad = cant;
    return peliculas;
}

int buscarPeliculaPorId(struct movie peliculas[], int cantPeliculas, int idMovie)
{
    int i = 0,flag=0;
    while(!flag && i<cantPeliculas)
    {
        if (peliculas[i].id == idMovie) {
            flag = 1;
        }
        i++;
    }
    
    if(flag)
    {
        return i-1;
    }
    else
    {
        return -1;
    }
    
}

// Recibe numero de genero y devuelve 1 si es y 0 si no es
int perteneceAGenero(struct movie pelicula, int indiceGenero)
{
    switch (indiceGenero) {
        case 0:  return pelicula.sGenero.Action;
        case 1:  return pelicula.sGenero.Adventure;
        case 2:  return pelicula.sGenero.Animation;
        case 3:  return pelicula.sGenero.Children;
        case 4:  return pelicula.sGenero.Comedy;
        case 5:  return pelicula.sGenero.Crime;
        case 6:  return pelicula.sGenero.Drama;
        case 7:  return pelicula.sGenero.Fantasy;
        case 8:  return pelicula.sGenero.Horror;
        case 9:  return pelicula.sGenero.IMAX;
        case 10: return pelicula.sGenero.Musical;
        case 11: return pelicula.sGenero.Mystery;
        case 12: return pelicula.sGenero.Romance;
        case 13: return pelicula.sGenero.SciFi;
        case 14: return pelicula.sGenero.Thriller;
        case 15: return pelicula.sGenero.War;
        case 16: return pelicula.sGenero.Western;
        case 17: return pelicula.sGenero.Documentary;
        case 18: return pelicula.sGenero.FilmNoir;
        default: return 0;
    }
}

// Devuelve el nombre del genero segun su numero
const char *obtenerNombreGenero(int indiceGenero)
{
    static const char *nombres[CANT_GENEROS] = {
        "Action",
        "Adventure",
        "Animation",
        "Children",
        "Comedy",
        "Crime",
        "Drama",
        "Fantasy",
        "Horror",
        "IMAX",
        "Musical",
        "Mystery",
        "Romance",
        "Sci-Fi",
        "Thriller",
        "War",
        "Western",
        "Documentary",
        "Film-Noir"
    };

    if (indiceGenero < 0 || indiceGenero >= CANT_GENEROS) {
        return "Genero desconocido";
    }

    return nombres[indiceGenero];
}