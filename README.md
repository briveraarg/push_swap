# push_swap
Swap_push no es tan natural

# Push_swap

Push_swap es un programa en C diseñado para ordenar una pila de números utilizando un conjunto de operaciones específicas. Es un desafío común en la escuela 42 y tiene como objetivo optimizar el número de movimientos necesarios para ordenar la pila.

## Características

- Implementación de un algoritmo eficiente para ordenar una pila.
- Soporte para operaciones básicas de manipulación de pilas.
- Versión adicional con verificación interactiva (*bonus*).

## Instalación

Para compilar el proyecto, usa el siguiente comando:

```sh
make
```

Esto generará el ejecutable `push_swap`. Para compilar la versión bonus, usa:

```sh
make bonus
```

Para limpiar archivos intermedios y objetos:

```sh
make clean
```

Para limpiar completamente los binarios generados:

```sh
make fclean
```

Para recompilar desde cero:

```sh
make re
```

## Uso

Ejecuta el programa pasando una serie de números como argumentos:

```sh
./push_swap 4 67 3 87 23
```

Esto imprimirá la secuencia de movimientos necesarios para ordenar la pila.

### Algoritmo de Ordenación

El programa utiliza diferentes estrategias de ordenación según la cantidad de números recibidos:

- Para `argv = 3`, se usa una simple comparación y swap si es necesario.
- Para `argv = 4`, se emplea una estrategia específica basada en swaps y rotaciones mínimas.
- Para `argv = 5` a `argv = 8`, se usa un algoritmo más estructurado con una mezcla de particionamiento y movimientos optimizados.
- Para `argv >= 9`, se implementa una estrategia basada en `ksort`, un método que divide los elementos en grupos, facilitando el ordenamiento mediante el uso eficiente de las operaciones permitidas.

Las operaciones permitidas son:

- `sa` (swap a): Intercambia los dos primeros elementos de la pila A.
- `sb` (swap b): Intercambia los dos primeros elementos de la pila B.
- `ss` (swap a y b): Realiza `sa` y `sb` simultáneamente.
- `pa` (push a): Mueve el primer elemento de la pila B a la pila A.
- `pb` (push b): Mueve el primer elemento de la pila A a la pila B.
- `ra` (rotate a): Desplaza todos los elementos de la pila A hacia arriba.
- `rb` (rotate b): Desplaza todos los elementos de la pila B hacia arriba.
- `rr` (rotate a y b): Realiza `ra` y `rb` simultáneamente.
- `rra` (reverse rotate a): Desplaza todos los elementos de la pila A hacia abajo.
- `rrb` (reverse rotate b): Desplaza todos los elementos de la pila B hacia abajo.
- `rrr` (reverse rotate a y b): Realiza `rra` y `rrb` simultáneamente.

### Pruebas de Rendimiento

Para validar este proyecto, se deben realizar pruebas de rendimiento con un número mínimo de operaciones:

- Para una validación mínima del proyecto (nota mínima de 80), el programa debe ser capaz de ordenar 100 números aleatorios en menos de 700 operaciones.
- Para una validación máxima del proyecto y obtener los bonus, además de cumplir el primer requisito, también debe ordenar 500 números aleatorios sin superar las 5500 operaciones.

### Checker (Bonus)

También se incluye un programa `checker_bonus` que verifica si la secuencia de movimientos aplicada ordena correctamente la pila:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_bonus $ARG
```

Si la secuencia es correcta, mostrará `OK`, de lo contrario, `KO`.

## Estructura del Proyecto

- `src/` - Implementación principal del algoritmo y funciones auxiliares.
- `bonus/` - Implementación de la versión interactiva.
- `include/` - Archivos de cabecera.
- `libs/libft/` - Biblioteca estándar personalizada.
- `Makefile` - Script para compilar el proyecto.

## Autores

Proyecto desarrollado por **Brenda Rivera** como parte del programa de la escuela 42.

## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo `LICENSE` para más detalles.

