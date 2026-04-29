# Ejercicios propuestos - Archivos en C

Este repositorio contiene la resolución de ejercicios prácticos de manejo de archivos en lenguaje C.

## Ejercicio 1

Realizar un programa para copiar un archivo de texto en otro.

### Objetivo

El programa debe abrir un archivo de texto existente, leer su contenido y copiarlo en un nuevo archivo de salida.

### Conceptos utilizados

- Apertura de archivos de texto.
- Lectura de caracteres o líneas.
- Escritura en otro archivo.
- Manejo de errores al abrir archivos.
- Cierre correcto de archivos.

---

## Ejercicio 2

Realizar un programa que maneje un archivo de longitud desconocida, donde cada registro contiene:

- Nombre de un alumno.
- Cuatro notas.

El programa debe hacerse con un menú que permita:

- Crear el archivo.
- Calcular el promedio.
- Mostrar los registros.
- Buscar un registro determinado.
- Modificar una nota.
- Agregar registros.
- Ordenar el archivo alfabéticamente.

También se debe realizar un programa que genere el archivo y permita verificar que funcione en conjunto.

### Objetivo

Administrar una base de datos simple de alumnos utilizando archivos, permitiendo cargar, consultar, modificar y ordenar registros.

### Conceptos utilizados

- Archivos de registros.
- Estructuras `struct`.
- Lectura y escritura de datos.
- Menú interactivo.
- Búsqueda de registros.
- Modificación de registros.
- Ordenamiento alfabético.
- Manejo de archivos de longitud variable o desconocida.

---

## Ejercicio 3

Se tiene un archivo `lista.dat` que contiene la base de datos de artículos de un negocio.

Cada artículo contiene los siguientes datos:

- Número de artículo: `int`
- Descripción: `string` de 30 caracteres
- Precio: `float`
- Proveedor: `string` de 30 caracteres
- Stock: `int`

Se debe actualizar esta base de datos aplicando un aumento del 20% a todos los artículos del proveedor Pérez.

También se debe realizar un programa que genere la base de datos y permita verificar que funcione en conjunto.

### Objetivo

Modificar registros dentro de un archivo binario, aplicando una actualización de precio según el proveedor del artículo.

### Conceptos utilizados

- Archivos binarios.
- Estructuras `struct`.
- Lectura y escritura de registros.
- Actualización de datos dentro de un archivo.
- Comparación de cadenas.
- Uso de `fread`, `fwrite`, `fseek` y `rewind`.

---

## Ejercicio 4

Escribir un programa que abra un archivo PNG en modo binario y muestre por pantalla:

1. Si el archivo es realmente un PNG válido.
2. El ancho y alto de la imagen en píxeles.

Para verificar si el archivo es un PNG válido se deben comprobar los primeros 8 bytes:

```text
89 50 4E 47 0D 0A 1A 0A
