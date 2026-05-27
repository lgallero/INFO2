/*
Ejercicio 1:

Supongamos que a lo largo de la ejecución de un programa en C, cada vez que se invoca a malloc o calloc se incrementase una variable global entera a modo de contador 
inicializada a cero, y cada vez que se invocase free se decrementase: 

¿Qué valor debería tener justo antes de terminar la ejecución?

Y si un programa termina su ejecución y esta variable vale cero, 

¿es esto suficiente para concluir que hace una gestión de memoria correcta?
*/


/*
Respuesta 1 :

*Cada vez que se llama a malloc() o calloc(), el contador aumenta en 1.
*Cada vez que se llama a free(), el contador disminuye en 1.

Entonces, justo antes de terminar la ejecución, el valor correcto debería ser: " 0 "

Porque si todo lo que pedimos con malloc() o calloc() fue liberado con free(), no debería quedar ningún bloque de memoria dinámica pendiente.


Respuesta 2 :

¿Si el contador termina en cero, alcanza para asegurar que la memoria fue bien gestionada?

No. No alcanza.

Que el contador termine en cero solo significa que hubo la misma cantidad de llamadas a funciones de reserva que de liberación:

*/