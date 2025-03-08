#!/bin/bash

# Variables para almacenar los mejores y peores resultados
best=999999
worst=0

# Ejecutar 100 veces
for i in $(seq 1 100); do
    # Generar 100 números aleatorios entre -5000 y 5000
    ARG=$(shuf <(seq -5000 5000) -n 100)
    
    # Ejecutar el programa push_swap y contar las líneas
    lines=$(./push_swap $ARG | wc -l)
    test=$(./push_swap $ARG | ./checker_linux $ARG)
    # Mostrar el número de líneas de esta ejecución
    echo "Ejecución $i: $lines líneas"
	echo "Ejecución $i: $test checker"
    
    if [ "$test" == "ko" ]; then
		echo -e "\033[31mError\033[0m"
	fi
	
	# Comparar con el mejor y peor
    if [ $lines -lt $best ]; then
        best=$lines
    fi
    
    if [ $lines -gt $worst ]; then
        worst=$lines
    fi
done

#     Mostrar los mejores y peores resultados
echo "Mejor número de líneas: $best"
echo "Peor número de líneas: $worst"
