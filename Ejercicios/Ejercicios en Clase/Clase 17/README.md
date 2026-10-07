# Clase 17: ejercicios de memoria dinámica

Los dos ejercicios están resueltos siguiendo la base de `ej17_mivector` del docente: atributos privados, métodos públicos, implementación separada y memoria reservada con `new[]` y liberada con `delete[]`. Se usan bucles y comparaciones simples.

## Cómo empezar

Cada ejercicio es un programa independiente y tiene su propio `main`. No hay que compilar los dos `main` juntos.

| Archivo | Qué mirar |
| --- | --- |
| `include/miVector.h` o `include/miString.h` | Los datos que guarda el objeto y los métodos disponibles. |
| `src/miVector.cpp` o `src/miString.cpp` | Cómo funciona cada método. |
| `src/main.cpp` | Cómo crear un objeto y llamar a sus métodos. |

Para estudiar, empezá por el `.h`, seguí con el constructor y después mirá cómo lo usa el `main`. El operador `::` indica a qué clase pertenece un método: `miVector::buscar` es el método `buscar` de la clase `miVector`.

## La idea que comparten los dos ejercicios

El objeto guarda un puntero y un tamaño. El puntero permite acceder al bloque de memoria; el tamaño dice cuántos elementos tenemos.

```cpp
int* m_vector {nullptr};
int m_tam;
```

`m_vector` no contiene todos los enteros dentro del propio puntero: guarda la dirección del bloque que se pidió con `new[]`. `m_tam` guarda el tamaño porque no podemos recuperarlo mirando solamente el puntero.

El constructor pide memoria cuando se crea el objeto. El destructor la libera cuando el objeto deja de existir. En los `main`, los objetos son locales; su destructor se ejecuta al salir normalmente del `main`, incluso si se sale antes con `return`.

```cpp
m_vector = new int [tam] {};  // Constructor: reserva y pone en cero.
delete[] m_vector;           // Destructor: libera ese bloque.
```

La pareja es `new[]` con `delete[]`. Los corchetes importan porque estamos trabajando con un arreglo.

## Ejercicio 1: ampliar miVector

Se conservaron el constructor, destructor, `setValor`, `getValor` y `getTam` del ejemplo. Se agregaron los cuatro métodos de la consigna. Ninguno recibe el tamaño: todos usan `m_tam`.

El constructor conserva el control `tam <= 0` y el `std::exit(0)` del docente. En el `main` no está el objeto de tamaño `-1` que él crea para mostrar un error: cortaría la ejecución antes de probar los métodos. Si ingresás un tamaño inválido, el constructor muestra el mensaje y termina. Como explica el docente, `exit` no ejecuta los destructores de los objetos locales; las excepciones quedan para otra clase.

### ordenar()

Usa burbujeo: compara dos elementos vecinos y los intercambia si el primero es mayor.

```cpp
if (m_vector[j] > m_vector[j + 1])
{
    int aux = m_vector[j];
    m_vector[j] = m_vector[j + 1];
    m_vector[j + 1] = aux;
}
```

`aux` guarda el primer valor mientras hacemos el intercambio. Sin esa variable, lo perderíamos al escribir encima.

Con `5 2 5 -1`, la primera pasada hace esto:

| Comparación | Vector después de comparar |
| --- | --- |
| `5` y `2`: intercambia. | `2 5 5 -1` |
| `5` y `5`: deja igual. | `2 5 5 -1` |
| `5` y `-1`: intercambia. | `2 5 -1 5` |

Al terminar esa pasada, un máximo ya quedó al final. Las siguientes pasadas repiten el proceso hasta obtener `-1 2 5 5`.

El bucle de afuera cuenta las pasadas. El de adentro recorre los vecinos. La condición `j < m_tam - 1 - i` evita acceder fuera del vector con `j + 1` y evita revisar la parte final que ya está ordenada. Con un solo elemento, no entra en los bucles porque ya está ordenado.

### buscar(int valor)

Recorre desde la posición cero. Cuando encuentra el valor, devuelve inmediatamente esa posición. Por eso devuelve la primera aparición aunque haya repetidos. Si llega al final sin encontrarlo, devuelve `-1`.

En `5 2 5 -1`, `buscar(5)` devuelve `0`. Después de ordenar, devuelve `2`. El valor sigue estando, pero su posición cambió. Buscar no necesita que el vector esté ordenado.

### imprimirMaximo() e imprimirMinimo()

Toman el primer elemento como candidato y recorren los restantes. El máximo se actualiza al encontrar uno mayor; el mínimo, al encontrar uno menor.

Se empieza con `m_vector[0]`, no con cero: en `-8 -3 -10`, el máximo es `-3`. Si se empezara con cero, se mostraría un número que ni siquiera está en el vector. El constructor garantiza que existe el primer elemento porque admite solamente tamaños positivos.

### Prueba desde el main

Ingresá estos datos, uno por línea:

```text
4
5
2
5
-1
5
```

El primer `4` es el tamaño, los siguientes cuatro números son los elementos y el último `5` es el valor a buscar. Los resultados principales serán:

```text
Vector cargado: 5 2 5 -1
Maximo: 5
Minimo: -1
Primera aparicion en la posicion 0
Vector ordenado: -1 2 5 5
Primera aparicion luego de ordenar: 2
```

Para probar un valor ausente, ejecutalo otra vez y buscá `99`. Debe avisar que no está. Las posiciones van de `0` a `tam - 1`.

## Ejercicio 2: crear miString

Los atributos son `char* m_cadena` e `int m_longitud`. La longitud cuenta los caracteres de la cadena sin incluir el terminador `\0`.

El constructor y los métodos `cargar` y `agregar` reciben `const char*`: un puntero a caracteres que esos métodos pueden leer pero no modificar. Las entradas deben ser cadenas válidas terminadas en `\0`, como los textos entre comillas del `main`.

### Constructor: medir, reservar y copiar

Para `miString obj1("Hola")`, el constructor cuenta cuatro caracteres. Después reserva cinco lugares y copia la cadena:

```text
Posición:    0    1    2    3     4
Contenido: 'H'  'o'  'l'  'a'  '\0'
```

La reserva es `new char[m_longitud + 1]`. Ese lugar adicional es necesario para que las funciones que leen una cadena sepan dónde termina.

El bucle de copia usa `i <= m_longitud`: con longitud cuatro, copia las posiciones de cero a cuatro, incluido el terminador. En cambio, el bucle que cuenta se detiene al encontrar `\0`, así que no lo suma a la longitud.

Aunque en el ejemplo se escriba `"Hola"` en el `main`, la clase calcula su longitud cuando se crea el objeto. No tiene un arreglo interno de tamaño fijo: reserva exactamente el espacio necesario para la cadena recibida.

### cargar(const char* cadena)

Reemplaza por completo el contenido. Por ejemplo, después de `obj1.cargar("Clase 17")`, el objeto guarda `"Clase 17"`, aunque antes tuviera `"Hola mundo"`.

El método mide la nueva cadena, reserva un bloque de `nuevaLongitud + 1` lugares y la copia, incluido su `\0`. Luego libera el bloque anterior, guarda la dirección del nuevo bloque y actualiza la longitud. Reservar y copiar antes de liberar permite conservar el contenido anterior mientras se prepara el reemplazo.

Esta parte conserva el acceso a la nueva memoria:

```cpp
delete[] m_cadena;
m_cadena = nuevaCadena;
m_longitud = nuevaLongitud;
```

Primero se libera el bloque anterior. Después se cambia el puntero. Si cambiáramos el puntero antes de liberar, perderíamos la dirección del bloque viejo.

`nuevaCadena` es un puntero local. Al terminar el método, ese puntero deja de existir, pero el bloque pedido con `new[]` sigue existiendo y su dirección quedó guardada en `m_cadena`.

### imprimir() y getLongitud()

`imprimir()` muestra `m_cadena` con `std::cout`. `getLongitud()` devuelve el número guardado en `m_longitud`. Para `"Hola"`, devuelve `4`, aunque el bloque reservado tenga cinco lugares.

### agregar(const char* texto)

Para pasar de `"Hola"` a `"Hola mundo"`, no podemos escribir más allá de los cinco lugares del bloque original. Hay que pedir uno nuevo.

1. Cuenta los seis caracteres de `" mundo"`, incluido el espacio.
2. Calcula la longitud final: `4 + 6 = 10`.
3. Reserva once lugares: diez caracteres y el terminador.
4. Copia `"Hola"` sin su `\0`.
5. Copia `" mundo"` a partir de la posición cuatro, incluyendo su `\0`.
6. Libera el bloque anterior y actualiza el puntero y la longitud.

La posición donde se copia el texto agregado es `m_longitud + i`. Si antes había cuatro caracteres, el primero nuevo va en la posición cuatro.

```text
Bloque viejo: H o l a \0
Bloque nuevo: H o l a   m u n d o \0
```

Se libera el bloque viejo después de copiarlo porque todavía lo necesitamos para leer sus caracteres. Se conserva un solo terminador al final del resultado.

### Qué prueba el main

El segundo programa no pide datos: usa cadenas cortas para que puedas seguir las llamadas y modificar los ejemplos. La consigna exige carga por teclado para el primer ejercicio; para el segundo, se demuestra cada método con estas llamadas:

| Operación | Contenido final | Longitud |
| --- | --- | ---: |
| Constructor con `"Hola"` | `Hola` | 4 |
| Agregar `" mundo"` | `Hola mundo` | 10 |
| Cargar `"Clase 17"` | `Clase 17` | 8 |
| Agregar `" - memoria dinamica"` | `Clase 17 - memoria dinamica` | 27 |
| Cargar `""` | Cadena vacía | 0 |
| Agregar `"Otra vez"` | `Otra vez` | 8 |

Una cadena vacía tiene longitud cero pero necesita un lugar para `\0`. Al terminar el programa, el destructor libera el último bloque. Los bloques anteriores ya fueron liberados por `cargar` o `agregar`.

## Compilar y ejecutar en Windows

Abrí una terminal PowerShell en esta carpeta:

```powershell
Set-Location 'D:\UTN\2do\INFO2\Mi Repo\INFO2\Ejercicios\Ejercicios en Clase\Clase 17'
.\compilar.ps1
```

Después ejecutá cada programa por separado:

```powershell
.\Ejercicio_1_miVector\ejercicio1.exe
.\Ejercicio_2_miString\ejercicio2.exe
```

También podés compilar directamente desde la carpeta `Clase 17`:

```powershell
g++ -Wall -Wextra -Wpedantic -std=c++17 -I Ejercicio_1_miVector/include Ejercicio_1_miVector/src/main.cpp Ejercicio_1_miVector/src/miVector.cpp -o Ejercicio_1_miVector/ejercicio1.exe
g++ -Wall -Wextra -Wpedantic -std=c++17 -I Ejercicio_2_miString/include Ejercicio_2_miString/src/main.cpp Ejercicio_2_miString/src/miString.cpp -o Ejercicio_2_miString/ejercicio2.exe
```

Hace falta compilar tanto el `main.cpp` como el `.cpp` de la clase. `-I` indica dónde están los encabezados.

## Alcance de estas clases

Como en la base del docente, no se implementa la copia de objetos que poseen memoria dinámica. Usá cada objeto directamente, como hacen los `main`; no copies uno con `miString otro = obj1` ni asignes objetos entre sí. Una copia de objetos requiere resolver también cómo se copia el bloque de memoria. Esto es distinto de copiar los caracteres recibidos por el constructor, que sí se hace aquí.

## Material utilizado

- Presentación **17 Gestión de memoria Dinámica en C++**, páginas 22 a 24, y la consigna de la captura.
- Código de la clase: `D:\UTN\2do\INFO2\informatica-ii\2026-2C\clase-17\ej17_mivector`.
- [Video del docente](https://www.youtube.com/watch?v=06CoG-8QbC8): desde 47:00 se desarrolla `miVector`; en 1:13:25 corrige los límites de las posiciones; en 1:16:28 explica la relación entre constructor, destructor y recursos; en 1:18:26 presenta los ejercicios propuestos. La transcripción automática se utilizó como apoyo junto con la presentación y el código.
