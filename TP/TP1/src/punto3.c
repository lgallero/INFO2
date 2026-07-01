#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

void Punto3 (struct movie peliculas[], int cantPeliculas, const char *archivoRatings)
{
    FILE *FP;
    struct rating ratingActual;
    struct usuarioGeneros *usuarios = NULL;
    struct usuarioGeneros *aux = NULL;
    int cantUsuarios = 0;
    int posUsuario;
    int posPelicula;
    int i;
    int j;
    int generoFavorito;
    int maxCantidad;

    FP = fopen(archivoRatings, "rb");
    if (FP == NULL) {
        printf("No se pudo abrir %s\n", archivoRatings);
        return;
    }

    while (fread(&ratingActual, sizeof(struct rating), 1, FP) == 1) 
    {
        posUsuario = buscarUsuarioPorId (usuarios, cantUsuarios, ratingActual.idUser);

        if (posUsuario == -1) { // Si no existe lo agrego

            aux = realloc (usuarios, (cantUsuarios + 1) * sizeof(struct usuarioGeneros)); // genero un espacio en memoria

            if (aux == NULL) {
                printf("No se pudo reservar memoria para usuarios\n");
                free(usuarios);
                fclose(FP);
                return; // CONSULTAR
            }

            usuarios = aux; 

            usuarios[cantUsuarios].idUser = ratingActual.idUser; // guardo su id 

            for (i = 0; i < CANT_GENEROS; i++) { // recorro los generos y los pongo en 0
                usuarios[cantUsuarios].cantidadGeneros[i] = 0;
            }

            posUsuario = cantUsuarios;
            cantUsuarios++;
        }

        posPelicula = buscarPeliculaPorId (peliculas, cantPeliculas, ratingActual.idMovie);

        if (posPelicula != -1) {  // si existe la pelicula 
            for (i = 0; i < CANT_GENEROS; i++) { // Recorro los generos
                if (perteneceAGenero(peliculas[posPelicula], i)) {
                    usuarios[posUsuario].cantidadGeneros[i]++; // Suma cada pelicula que tengo el genero que corresponde
                }
            }
        }
    }

    fclose(FP);

    printf("%-12s %-20s %-15s\n", "Usuario", "Genero favorito", "Cantidad");
    printf("------------------------------------------------\n");

    for (i = 0; i < cantUsuarios; i++) { // Recorro cada usuario

        generoFavorito = 0; // posicion del genero favorito dentro del usuario
        maxCantidad = usuarios[i].cantidadGeneros[0]; // cantidad maxima de reseñas 

        for (j = 1; j < CANT_GENEROS; j++) {
            if (usuarios[i].cantidadGeneros[j] > maxCantidad) {
                maxCantidad = usuarios[i].cantidadGeneros[j];
                generoFavorito = j;
            }
        }

        printf("%-12d %-20s %-15d\n", usuarios[i].idUser, obtenerNombreGenero(generoFavorito), maxCantidad);
    }

    free(usuarios);
}

int buscarUsuarioPorId( struct usuarioGeneros usuarios[], int cantUsuarios, int idUser)
{
    int i = 0, flag = 0;
    while (!flag && i < cantUsuarios )
    {
        if (usuarios[i].idUser == idUser) {
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