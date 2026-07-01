#ifndef TP1_H
#define TP1_H

/* ===========================================================================
 *  TP1 - "Archivos cruzados"  |  Informatica II
 *  Tipos de datos provistos por la catedra.
 *
 *  NO modifiques los structs: 'movies1.dat' esta grabado como un volcado
 *  binario de 'struct movie', asi que para leerlo con fread tu struct tiene
 *  que coincidir byte a byte (mismo orden de campos, mismos tipos). Si lo
 *  cambias, fread devuelve basura.
 *
 *  De ahi en mas el diseno del programa es TUYO: crea los .c que quieras
 *  dentro de src/, divididos en las funciones que te parezca.
 * ===========================================================================
 */

#define MAX_NOMBRE   200
#define CANT_GENEROS  19

/* Cada campo es un flag: vale 1 si la pelicula pertenece a ese genero, 0 si no.
 * El orden y la cantidad de campos importan: asi se grabo movies1.dat. */
typedef struct {
    char Action;
    char Adventure;
    char Animation;
    char Children;
    char Comedy;
    char Crime;
    char Drama;
    char Fantasy;
    char Horror;
    char IMAX;
    char Musical;
    char Mystery;
    char Romance;
    char SciFi;        /* Sci-Fi */
    char Thriller;
    char War;
    char Western;
    char Documentary;
    char FilmNoir;     /* Film-Noir */
} genero;

struct movie {
    int    id;
    char   nombre[MAX_NOMBRE];
    genero sGenero;
};

struct rating {
    int   idUser;
    int   idMovie;
    float rating;
    int   timeStamp;
};

// Estructura para PUNTO 3 
struct usuarioGeneros {
    int idUser;
    int cantidadGeneros[CANT_GENEROS];
};

// ==================== FUNCIONES GENERALES ====================

struct movie *leerPeliculas(const char *nombreArchivo, int *cantidad);

int buscarPeliculaPorId (struct movie peliculas[], int cantPeliculas, int idMovie);

int perteneceAGenero (struct movie pelicula, int indiceGenero);

const char *obtenerNombreGenero(int indiceGenero);

int parsearLineaMovieCsv(char linea[], struct movie *pelicula);

void limpiarGeneros(genero *g);

void cargarGeneroDesdeTexto (genero *g, const char *textoGenero);

int buscarUsuarioPorId (struct usuarioGeneros usuarios[], int cantUsuarios, int idUser);

// ==================== FUNCIONES DE LOS PUNTOS ====================
void Punto1 (struct movie peliculas[], int cantPeliculas,const char *archivoRatings);

void Punto2 (const char *archivoMoviesOriginal, const char *archivoMoviesCsv, const char *archivoMoviesFinal);

void Punto3 (struct movie peliculas[], int cantPeliculas, const char *archivoRatings);
#endif /* TP1_H */
