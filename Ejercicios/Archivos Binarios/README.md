# Ejercicios propuestos

1. Realizar un programa para copiar un archivo de texto en otro.

2. Realizar un programa que maneje un archivo de longitud desconocida, donde cada registro contiene el nombre de un alumno y cuatro notas. Hacerlo con un menú que permita crear el archivo, calcular el promedio, mostrarlo, buscar un registro determinado, modificar una nota, agregar registros y ordenarlo en el archivo alfabéticamente. Realizar también el programa que genere el archivo y verificar que funcionen en conjunto.

3. Se tiene un archivo `lista.dat`, que contiene la Base de Datos de artículos de un negocio:

   - Número de artículo (`int`),
   - Descripción (`string` de 30 caracteres),
   - precio (`float`),
   - proveedor (`string` de 30)
   - stock(`int`).

   Actualizar esta Base de Datos aplicando un 20% de aumento a todos los artículos del proveedor Pérez.

   Realizar también el programa que genere la base de datos y verificar que funcionen en conjunto.

---

# Ejercicios propuestos

4. Escribir un programa que abra un archivo PNG en modo binario y muestre por pantalla:

   A. Si el archivo es realmente un PNG válido (verificando los primeros 8 bytes: `89 50 4E 47 0D 0A 1A 0A`).

   B. El ancho y alto de la imagen en píxeles.

Datos del formato:

- Los primeros 8 bytes son la firma PNG.

- A continuación viene un chunk llamado IHDR. Su estructura comienza así:

  - 4 bytes: tamaño del chunk (`uint32_t`, big-endian) — ignorarlo.
  - 4 bytes: tipo del chunk (los caracteres ASCII `"IHDR"`) — ignorarlos.
  - 4 bytes: ancho (`uint32_t`, big-endian).
  - 4 bytes: alto (`uint32_t`, big-endian).
  - Los `uint32_t` están en big-endian (network byte order). Como las PCs son little-endian, hay que invertir el orden de los bytes al leer.

Probar el programa con varios PNG de ancho y alto conocido. Verificar el resultado abriendo la imagen en cualquier visor.
