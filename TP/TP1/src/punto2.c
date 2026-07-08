#include <stdio.h>
#include <string.h>
#include "tp1.h"

static int leerMovieCsv(FILE *fpCsv, struct movie *pelicula);
static void asignarGenero(genero *g, const char *nombreGenero);

void Punto2(const char *archivoMoviesOriginal, const char *archivoMoviesCsv, const char *archivoMoviesFinal)
{
    FILE *fpOriginal;
    FILE *fpCsv;
    FILE *fpFinal;

    struct movie pelicula;
    int peliculasAgregadas = 0;

    fpOriginal = fopen(archivoMoviesOriginal, "rb");
    if (fpOriginal == NULL) {
        printf("No se pudo abrir %s\n", archivoMoviesOriginal);
        return;
    }

    fpFinal = fopen(archivoMoviesFinal, "wb");
    if (fpFinal == NULL) {
        printf("No se pudo crear %s\n", archivoMoviesFinal);
        fclose(fpOriginal);
        return;
    }

    // Copia del Original
    while (fread(&pelicula, sizeof(struct movie), 1, fpOriginal) == 1) {
        fwrite(&pelicula, sizeof(struct movie), 1, fpFinal);
    }

    fclose(fpOriginal);

    fpCsv = fopen(archivoMoviesCsv, "r");
    if (fpCsv == NULL) {
        printf("No se pudo abrir %s\n", archivoMoviesCsv);
        fclose(fpFinal);
        return;
    }

    // Parsear y copiar el .csv
    while (leerMovieCsv(fpCsv, &pelicula)) {
        fwrite(&pelicula, sizeof(struct movie), 1, fpFinal);
        peliculasAgregadas++;
    }

    fclose(fpCsv);
    fclose(fpFinal);

    printf("Peliculas agregadas desde movies2.csv: %d\n", peliculasAgregadas);
    printf("Se creo el archivo %s\n\n", archivoMoviesFinal);
}

// Devuelve 1 si se completo , 0 si hubo algun error 
static int leerMovieCsv(FILE *fpCsv, struct movie *pelicula)
{
    char generosTexto[250];
    int caracter;

    if (fscanf(fpCsv, " %d,", &pelicula->id) != 1) { // ID :  id, 
        return 0;
    }

    memset(pelicula->nombre, 0, MAX_NOMBRE); // Limpio el nombre 

    limpiarGeneros(&pelicula->sGenero);      // Limpio todos los generos 


    caracter = fgetc(fpCsv);
   
    if (caracter == '"') {
        if (fscanf(fpCsv, " %199[^\"]\"", pelicula->nombre) != 1) {  // Viene con comillas 
            return 0;
        }
    } else { 
        fseek(fpCsv, -1, SEEK_CUR);

        if (fscanf(fpCsv, " %199[^,]", pelicula->nombre) != 1) {     // No viene con comillas 
            return 0;
        }
    }

    if (fscanf(fpCsv, ", %249[^\n]", generosTexto) != 1) { // leo todos los generos hasta el fin de la linea
        return 0;
    }

    cargarGeneroDesdeTexto(&pelicula->sGenero, generosTexto);

    return 1;
}

// Pone en 0 todos los generos
void limpiarGeneros(genero *g)
{
    g->Action = 0;
    g->Adventure = 0;
    g->Animation = 0;
    g->Children = 0;
    g->Comedy = 0;
    g->Crime = 0;
    g->Drama = 0;
    g->Fantasy = 0;
    g->Horror = 0;
    g->IMAX = 0;
    g->Musical = 0;
    g->Mystery = 0;
    g->Romance = 0;
    g->SciFi = 0;
    g->Thriller = 0;
    g->War = 0;
    g->Western = 0;
    g->Documentary = 0;
    g->FilmNoir = 0;
}

// Parsea los generos
void cargarGeneroDesdeTexto(genero *g, const char *textoGenero)
{
    char copia[250];
    char *token;     

    strncpy(copia, textoGenero, sizeof(copia) - 1); // Hago una copia
    copia[sizeof(copia) - 1] = '\0';                // Caracter nulo en el final para asegurar el final

    token = strtok(copia, "|"); // Copio hasta |

    while (token != NULL) {
        asignarGenero(g, token);  
        token = strtok(NULL, "|");
    }
}

// Pone en 1 el genero leido por texto
static void asignarGenero(genero *g, const char *nombreGenero)
{
    if (strcmp(nombreGenero, "Action") == 0) {
        g->Action = 1;
    } else if (strcmp(nombreGenero, "Adventure") == 0) {
        g->Adventure = 1;
    } else if (strcmp(nombreGenero, "Animation") == 0) {
        g->Animation = 1;
    } else if (strcmp(nombreGenero, "Children") == 0) {
        g->Children = 1;
    } else if (strcmp(nombreGenero, "Comedy") == 0) {
        g->Comedy = 1;
    } else if (strcmp(nombreGenero, "Crime") == 0) {
        g->Crime = 1;
    } else if (strcmp(nombreGenero, "Drama") == 0) {
        g->Drama = 1;
    } else if (strcmp(nombreGenero, "Fantasy") == 0) {
        g->Fantasy = 1;
    } else if (strcmp(nombreGenero, "Horror") == 0) {
        g->Horror = 1;
    } else if (strcmp(nombreGenero, "IMAX") == 0) {
        g->IMAX = 1;
    } else if (strcmp(nombreGenero, "Musical") == 0) {
        g->Musical = 1;
    } else if (strcmp(nombreGenero, "Mystery") == 0) {
        g->Mystery = 1;
    } else if (strcmp(nombreGenero, "Romance") == 0) {
        g->Romance = 1;
    } else if (strcmp(nombreGenero, "Sci-Fi") == 0) {
        g->SciFi = 1;
    } else if (strcmp(nombreGenero, "Thriller") == 0) {
        g->Thriller = 1;
    } else if (strcmp(nombreGenero, "War") == 0) {
        g->War = 1;
    } else if (strcmp(nombreGenero, "Western") == 0) {
        g->Western = 1;
    } else if (strcmp(nombreGenero, "Documentary") == 0) {
        g->Documentary = 1;
    } else if (strcmp(nombreGenero, "Film-Noir") == 0) {
        g->FilmNoir = 1;
    }
}
