# TP2 — Matriz dinámica

**Informática II** · Trabajo Práctico 2 · Clases y memoria dinámica en C++

> Este TP tiene **dos partes**. Este enunciado es la **parte 1**. La parte 2 se
> publica más adelante, en este mismo repo.

---

## Consigna

Implementar la clase `matriz`, una matriz dinámica de enteros:

```cpp
class matriz
{
private:
    int m_filas, m_columnas;
    int **m_mat;
public:
    matriz (int , int ) ;
    ~matriz();
    int getFilas ();
    int getColumnas ();
    int getDatoEn (int , int) ;
    void setDato (int , int , int );
    void printAll();
};
```

**Se pide:**

1. Implementar la clase siguiendo la lógica **RAII** (Resource Acquisition Is
   Initialization): la asignación y la liberación de la memoria de la matriz
   deben estar correctamente gestionadas en el constructor y el destructor.
2. Utilizar un archivo de cabecera `.h` y uno de implementación `.cpp` para la
   clase.
3. En el `main`, instanciar objetos tipo `matriz` tanto en el stack:
   ```cpp
   matriz m1(3,3);
   ```
   como en el heap:
   ```cpp
   matriz *m2 = new matriz (4,4);
   //delete m2;
   ```
   Analizar cuándo se ejecutan los constructores y destructores en ambos casos.

### Parte 1

A la implementación anterior se le agregan los siguientes ítems:

- Al instanciarse el objeto debe inicializarse como la **matriz identidad** en
  caso de ser una matriz cuadrada, o con todos los elementos en **cero** en otro
  caso.
- Debe indicar **error** al intentar usar números de filas o columnas inválidos.
- Un método para transformar la matriz en su traspuesta:
  ```cpp
  void transpose ();   // No recibe ningún parámetro.
  ```
- Un método para asignar todos los elementos de la matriz con un valor:
  ```cpp
  void setAll ( int ); // Recibe por parámetro un elemento y asigna ese valor a todos los elementos de la matriz.
  ```
- Un método para agregar una nueva fila al final de la matriz:
  ```cpp
  void addFila ( int ); // Se debe inicializar con el valor recibido como parámetro.
  ```
- Un método para agregar una nueva columna al final de la matriz:
  ```cpp
  void addCol ( int );  // Se debe inicializar con el valor recibido como parámetro.
  ```

**Fecha de entrega:** se informa por el campus virtual.

---

## Cómo trabajar este repo

El flujo es el mismo del TP1: clonar por SSH, trabajar en una rama, compilar
con `make` y entregar con un Pull Request hacia `main`.

```bash
git clone git@github.com:informatica-ii-2026/<tu-repo>.git
git checkout -b parte1
make            # genera ./tp2 (make run lo ejecuta, make clean limpia)
git push -u origin parte1
```

- Los `.h` van en `include/` y los `.cpp` en `src/`. Estructura sugerida:
  `include/matriz.h`, `src/matriz.cpp` y `src/main.cpp`.
- El trabajo **debe compilar con `make`**, sin errores ni warnings.
- El `Makefile` no se toca.

**Parte 2.** Cuando se publique, el enunciado va a aparecer en este README. Se
trabaja en una rama nueva, creada desde `main` actualizado, y se entrega con
otro Pull Request:

```bash
git checkout main
git pull
git checkout -b parte2
```

---

**Integrantes del grupo:** completá acá los nombres y legajos.

| Nombre | Legajo | Usuario GitHub |
|--------|--------|----------------|
|        |        |                |
|        |        |                |
