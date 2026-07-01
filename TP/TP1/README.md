# TP1 — Archivos cruzados

**Informática II** · Trabajo Práctico 1 · Manejo de archivos en C

---

## Consigna

El archivo `movies1.dat` (obtenido a partir de `movies1.csv`, fuente
[MovieLens](https://grouplens.org/datasets/movielens/)) contiene un listado de
películas y su género, grabado como una secuencia de structs:

```c
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
    char SciFi;        // Sci-Fi
    char Thriller;
    char War;
    char Western;
    char Documentary;
    char FilmNoir;     // Film-Noir
} genero;

struct movie {
    int    id;
    char   nombre[200];
    genero sGenero;
};
```

El archivo `ratings1.dat` contiene las calificaciones que distintos usuarios le
dieron a esas películas:

```c
struct rating {
    int   idUser;
    int   idMovie;
    float rating;
    int   timeStamp;
};
```

**Se pide:**

1. Calcular la calificación **promedio de cada género** (promedio sobre todas
   las películas de Acción, Aventura, etc.). Imprimirlos en pantalla.
2. **Concatenar** `movies2.csv` a `movies1.dat` y volver a repetir el punto 1.
3. Determinar el **género favorito de cada usuario**, considerando que prefieren
   los géneros que califican más cantidad de veces.

---

## Los datos

Los archivos de datos **no están en el repo** (son grandes y binarios; se
versiona código, no datos). Bajalos del **campus virtual**, descomprimilos y
dejalos dentro de la carpeta `data/`:

```
data/
├── movies1.dat
├── ratings1.dat
└── movies2.csv
```

El programa los busca en esas rutas (ver `src/main.c`).

---

## Cómo trabajar este repo

> ℹ️ **Importante — esto es nuevo.** GitHub **no compila ni ejecuta** tu
> programa: es solo el lugar donde viven los archivos (un repositorio
> compartido con historial). Vos programás, compilás y corrés **en tu propia
> computadora**, con la herramienta que ya usás. Lo único nuevo respecto de
> antes es cómo bajás el código y cómo lo entregás.

**El ciclo completo:**

1. **Clonar** este repo a tu PC **por SSH** (con la clave que ya configuraste en
   tu cuenta de GitHub):
   ```bash
   git clone git@github.com:informatica-ii-2026/<tu-repo>.git
   ```
   Reemplazá `<tu-repo>` por el nombre del tuyo (ej. `tp1-g05`). Esa URL la
   copiás de tu repo en **Code → pestaña SSH** (empieza con `git@github.com:`,
   **no** con `https://`: la `https://...` del navegador te haría pedir token).
2. **Bajar los datos** del campus virtual y dejarlos en `data/` (ver arriba).
3. **Crear tu rama de trabajo**: `git checkout -b trabajo` (no se programa sobre
   `main` — ver "Entrega" más abajo).
4. **Programar** la solución (creá tus `.c` dentro de `src/`) con tu editor/IDE.
5. **Compilar y correr** en tu máquina (ver las dos opciones de abajo).
6. **Entregar**: `git add .` → `git commit -m "..."` → `git push -u origin trabajo`
   → **abrir el Pull Request de tu rama hacia `main`** desde GitHub. Esa es la
   entrega (detalle en "Entrega" más abajo).

Los pasos 4 y 5 son exactamente como siempre. Lo nuevo es bajar el código (1) y
entregarlo por rama + PR (3 y 6).

### Compilación: obligatoria con `make`

> ⚠️ **Requisito de entrega.** El trabajo **debe compilar con `make`** desde una
> terminal, sin errores ni warnings (se compila con `-Wall -Wextra`). Lo vimos
> en la teoría y es parte de lo que se evalúa. La corrección se hace corriendo
> `make` sobre su repo: si no compila así, no se corrige.

```bash
make        # compila -> genera el ejecutable ./tp1
make run    # compila y ejecuta
make clean  # borra objetos y ejecutable
```

Necesitás `gcc` y `make` instalados. En Windows vienen con MinGW (el mismo que
usa CodeBlocks); ahí el comando puede ser `mingw32-make` en lugar de `make`.

### El editor es libre

Compilar con `make` es obligatorio; **con qué editás, no**. Usá lo que prefieras:

- **CodeBlocks, VSCode, gedit, vim...** para escribir el código, todos sirven.
- Pero antes de entregar, **verificá en la terminal que `make` compile limpio**.
  Si en tu IDE anda pero `make` falla, todavía no está listo para entregar.

GitHub, por su parte, no compila nada: solo guarda los archivos. El código
fuente es el mismo sin importar el editor.

---

## Estructura del proyecto

```
.
├── include/tp1.h     # structs provistos por la cátedra (NO se tocan)
├── src/
│   └── main.c        # punto de entrada — arrancá acá y armá el resto
├── data/             # los datos del campus van acá (gitignored)
├── Makefile
└── README.md
```

`include/tp1.h` trae los **structs** con los que está grabado `movies1.dat`
(no los toques: si tu struct no coincide byte a byte, `fread` lee basura). De
ahí en más **el diseño es suyo**: creá los `.c` que quieras dentro de `src/`,
dividí en las funciones que te parezca y completá el `main`. El `Makefile`
compila automáticamente cualquier `.c` que agregues a `src/`.

El proyecto **compila desde el día cero**: `main.c` arranca con un `main()`
mínimo que ya enlaza, así `make` te entrega el ejecutable de entrada. A partir
de ahí, programá.

---

## Entrega (flujo de trabajo)

Este repositorio es **de su grupo**. Trabajen con commits frecuentes y mensajes
claros. **La entrega es por rama + Pull Request** — `main` está protegido y
**no se puede pushear directo** (te lo rechaza): todo entra por PR aprobado.

1. Creen una rama de trabajo: `git checkout -b trabajo` (o una por
   funcionalidad: `git checkout -b punto1-promedios`).
2. Hagan commits a medida que avanzan y pusheen la rama:
   `git push -u origin trabajo`.
3. Abran un **Pull Request** de esa rama hacia `main` de su propio repo. **Ese
   PR es la entrega.**
4. La corrección y la devolución de la cátedra se hacen **sobre ese mismo PR**
   (comentarios línea por línea). Con la aprobación del docente, recién ahí
   pueden mergear a `main`.

**Integrantes del grupo:** completá acá los nombres y legajos.

| Nombre | Legajo | Usuario GitHub |
|--------|--------|----------------|
| Gallero, Lucas | 25632 | lgallero |
|  Lukjanowioz,Esteban      |   27985     |  estebanlukja              |
