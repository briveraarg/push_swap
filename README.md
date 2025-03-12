# Push_swap

Push_swap es un programa en C diseñado para ordenar una pila de números utilizando un conjunto de operaciones específicas. Es un desafío común en 42 Madrid y tiene como objetivo optimizar el número de movimientos necesarios para ordenar la pila.

## Características

- Implementación de un algoritmo óptimo para ordenar una pila.
- Soporte para operaciones básicas de manipulación de pilas.
- Versión adicional con verificación interactiva (*bonus*).

## Instalación

Clona el repositorio:

```sh
git clone https://github.com/tusuario/push_swap.git
```

Para compilar el proyecto, usa el siguiente comando:

```sh
make
```

Esto generará el ejecutable `push_swap`. Para compilar la versión bonus, usa:

```sh
make bonus
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

Para verificar el resultado con el *checker* correspondiente a tu sistema operativo:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_SO $ARG
```

Esto imprimirá la secuencia de movimientos necesarios para ordenar la pila y el *checker* comprobará si está todo OK.

## Estrategias para ordenar

El programa utiliza diferentes estrategias de ordenación según la cantidad de números recibidos:

- Para `argv = 3`, se usa una simple comparación y swap si es necesario.

  [`stack_sort_three(stack_a`)](https://github.com/briveraarg/push_swap/blob/main/src/stack_sort_01.c)
  
- Para `argv = 4`, se emplea una estrategia basada en swaps y rotaciones mínimas.
  
  [`stack_sort_four(stack_a, &stack_b);`](https://github.com/briveraarg/push_swap/blob/main/src/stack_sort_01.c)
  
- Para `argv = 5` a `argv = 8`, se usa una función más estructurada que emplea índices con una mezcla de particionamiento y movimientos optimizados.
  
  [`stack_sort_five_and_eight(stack_a, stack_b, lim);`](https://github.com/briveraarg/push_swap/blob/main/src/stack_sort_01.c)

- Para `argv >= 9`, se implementa una estrategia basada en `ksort`, que divide los elementos en grupos de acuerdo a un rango, facilitando el ordenamiento mediante el uso de índices con las operaciones permitidas.
  
  [`k_sort_phase_one(stack_a, stack_b);`](https://github.com/briveraarg/push_swap/blob/main/src/stack_sort_02.c)
  [`k_sort_phase_two(stack_a, stack_b, size_a);`](https://github.com/briveraarg/push_swap/blob/main/src/stack_sort_02.c)
  
  Para generar los índices, se usa la función:
  
  [`load_index_with_timsort(t_stack *stack_a);`](https://github.com/briveraarg/push_swap/blob/main/src/stack_sort_04.c)
  

### Operaciones permitidas

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

## Pruebas de rendimiento

Para validar este proyecto, se deben realizar pruebas de rendimiento con un número mínimo de operaciones:

- Para una validación mínima (nota 80), el programa debe ordenar 100 números aleatorios en menos de 700 operaciones.
- Para una validación máxima y obtener los *bonus*, además de cumplir el primer requisito, también debe ordenar 500 números aleatorios sin superar las 5500 operaciones.

Para hacer pruebas de forma sistemática, puedes usar el siguiente script:

```bash
#!/bin/bash

best=999999
worst=0

for i in $(seq 1 100); do
    ARG=$(shuf <(seq -5000 5000) -n 500)
    lines=$(./push_swap $ARG | wc -l)
    test=$(./push_swap $ARG | ./checker_linux $ARG)
    echo "Ejecución $i: $lines líneas"
    echo "Ejecución $i: $test checker"

    if [ "$test" == "KO" ]; then
        echo -e "\033[31mError\033[0m"
    fi

    if [ $lines -lt $best ]; then
        best=$lines
    fi

    if [ $lines -gt $worst ]; then
        worst=$lines
    fi

done

echo "Mejor número de líneas: $best"
echo "Peor número de líneas: $worst"
```

## Checker (Bonus)

El proyecto incluye un *checker* que verifica si la secuencia de movimientos aplicada ordena correctamente la pila:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

```sh
 ./checker 2 1 7
sa
OK
```

Si la secuencia es correcta, mostrará `OK`, de lo contrario, `KO` o `Error` si los argumentos son incorrectos.

## Estructura del proyecto

- `src/` - Implementación principal del algoritmo y funciones auxiliares.
- `bonus/` - Implementación de la versión BONUS del proyecto.
- `include/` - Archivos de cabecera.
- `libs/libft/` - Biblioteca estándar personalizada.
- `Makefile` - Script para compilar el proyecto.

## Recomendación

Si necesitas más información, te recomiendo leer la documentación de Oliver, ya que explica en detalle cada parte del proyecto. No dudes en darle una estrella:

[Repositorio de Oli](https://github.com/oliverkingz/push_swap)

## Autora

Proyecto desarrollado por **Brenda Rivera** como parte del programa de 42 Madrid.

## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo `LICENSE` para más detalles.



