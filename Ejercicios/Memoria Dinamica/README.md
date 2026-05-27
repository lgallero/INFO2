# Ejercitación

1. Supongamos que a lo largo de la ejecución de un programa en C, cada vez que se invoca a `malloc` o `calloc` se incrementase una variable global entera a modo de contador inicializada a cero, y cada vez que se invocase `free` se decrementase: ¿Qué valor debería tener justo antes de terminar la ejecución?  
   Y si un programa termina su ejecución y esta variable vale cero, ¿es esto suficiente para concluir que hace una gestión de memoria correcta?

2. Ingresar por teclado un entero que represente la cantidad de elementos que debe crearse un vector. Crear el vector en forma dinámica, cargar e imprimir sus datos. Hacer todo en `main`.

3. Se tiene la siguiente declaración de registro:

        struct producto {
            int codigo;
            char descripcion[41];
            float precio;
        };

   Definir un puntero de tipo producto y luego mediante la función `malloc` crear un registro en la pila dinámica. Cargar el registro, imprimirlo y finalmente liberar el espacio reservado mediante la función `free`.

4. Pedir ingresar por teclado cuantas letras tiene una palabra. Seguidamente crear un vector en forma dinámica que reserve el espacio mínimo para ingresar dicha palabra.  
   Cargar por teclado la palabra, mostrarla y finalmente liberar el espacio requerido.