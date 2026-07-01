#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp1.h"

void Punto2 (const char *archivoMoviesOriginal, const char *archivoMoviesCsv, const char *archivoMoviesFinal)
{
    FILE *fpOriginal;
    FILE *fpCsv;
    FILE *fpFinal;
    struct movie pelicula;
    char linea[500];
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

    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
    while (fgets(linea, sizeof(linea), fpCsv) != NULL) {
        if (parsearLineaMovieCsv(linea, &pelicula)) {
            fwrite(&pelicula, sizeof(struct movie), 1, fpFinal);
            peliculasAgregadas++;
        }
    }
    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
    fclose(fpCsv);
    fclose(fpFinal);

    printf("Peliculas agregadas desde movies2.csv: %d\n", peliculasAgregadas);
    printf("Se creo el archivo %s\n\n", archivoMoviesFinal);
}
// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
int parsearLineaMovieCsv(char linea[], struct movie *pelicula)
{
    char *ptr;
    char *finId;
    char generosTexto[250];
    int i = 0;

    linea[strcspn(linea, "\n")] = '\0';

    ptr = linea;

    pelicula->id = (int)strtol(ptr, &finId, 10);

    if (ptr == finId) {
        return 0;
    }

    if (*finId != ',') {
        return 0;
    }

    ptr = finId + 1;

    memset(pelicula->nombre, 0, MAX_NOMBRE);
    limpiarGeneros(&pelicula->sGenero);

    if (*ptr == '"') {
        ptr++;

        while (*ptr != '\0' && !(*ptr == '"' && *(ptr + 1) == ',')) {
            if (i < MAX_NOMBRE - 1) {
                pelicula->nombre[i] = *ptr;
                i++;
            }
            ptr++;
        }

        pelicula->nombre[i] = '\0';

        if (*ptr == '"') {
            ptr++;
        }

        if (*ptr == ',') {
            ptr++;
        }
    } else {
        while (*ptr != '\0' && *ptr != ',') {
            if (i < MAX_NOMBRE - 1) {
                pelicula->nombre[i] = *ptr;
                i++;
            }
            ptr++;
        }

        pelicula->nombre[i] = '\0';

        if (*ptr == ',') {
            ptr++;
        }
    }

    strncpy(generosTexto, ptr, sizeof(generosTexto) - 1);
    generosTexto[sizeof(generosTexto) - 1] = '\0';

    cargarGeneroDesdeTexto(&pelicula->sGenero, generosTexto);

    return 1;
}
// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
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

void cargarGeneroDesdeTexto(genero *g, const char *textoGenero)
{
    if (strstr(textoGenero, "Action") != NULL) {
        g->Action = 1;
    }

    if (strstr(textoGenero, "Adventure") != NULL) {
        g->Adventure = 1;
    }

    if (strstr(textoGenero, "Animation") != NULL) {
        g->Animation = 1;
    }

    if (strstr(textoGenero, "Children") != NULL) {
        g->Children = 1;
    }

    if (strstr(textoGenero, "Comedy") != NULL) {
        g->Comedy = 1;
    }

    if (strstr(textoGenero, "Crime") != NULL) {
        g->Crime = 1;
    }

    if (strstr(textoGenero, "Drama") != NULL) {
        g->Drama = 1;
    }

    if (strstr(textoGenero, "Fantasy") != NULL) {
        g->Fantasy = 1;
    }

    if (strstr(textoGenero, "Horror") != NULL) {
        g->Horror = 1;
    }

    if (strstr(textoGenero, "IMAX") != NULL) {
        g->IMAX = 1;
    }

    if (strstr(textoGenero, "Musical") != NULL) {
        g->Musical = 1;
    }

    if (strstr(textoGenero, "Mystery") != NULL) {
        g->Mystery = 1;
    }

    if (strstr(textoGenero, "Romance") != NULL) {
        g->Romance = 1;
    }

    if (strstr(textoGenero, "Sci-Fi") != NULL) {
        g->SciFi = 1;
    }

    if (strstr(textoGenero, "Thriller") != NULL) {
        g->Thriller = 1;
    }

    if (strstr(textoGenero, "War") != NULL) {
        g->War = 1;
    }

    if (strstr(textoGenero, "Western") != NULL) {
        g->Western = 1;
    }

    if (strstr(textoGenero, "Documentary") != NULL) {
        g->Documentary = 1;
    }

    if (strstr(textoGenero, "Film-Noir") != NULL) {
        g->FilmNoir = 1;
    }
}