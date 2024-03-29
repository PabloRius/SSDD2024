#include <stdio.h>
#include <stdlib.h>

void readArgs(int *length, char **argv, int *array){
    int delay = 0;
    int new_length = *length;
	for(int i = 1;i < *length + 1; i++){
			char* end;
			long int value = strtol(argv[i],&end,10);
			if(*end == '\0'){
				// Valor transformado a entero
                array[i - 1 - delay] = value;
			}else{
				// El valor introducido no era un entero, se salta, se acorta el tamaño de la lista en 1
                // He introducido la variable delay para que, si hay un no entero en los argumentos, no se escriba en el array, 
                // pero el resto de valores sigan el orden para que no queden huecos vacios
                // La variable que guarda la longitud del array se modifica para que el resto de funciones pueda tener el tamaño actualizado.
                delay += 1;
                new_length -= 1;
			}
			
		}
    *length = new_length;
        
}

void printArray(int length, int *array){
    printf("[");
    for (int i = 0; i < length; i++){
            printf("%d",array[i]);
            if(i < length - 1){
                printf(", ");
            }
        }
    printf("]\n");
}

int compareFunction(const void *_a, const void *_b){
    int *a, *b;
    a = (int *) _a;
    b = (int *) _b;

    return (*a - *b);
}

void ordenarIntArray(int length, int *array){
    qsort(array, length, sizeof(int), compareFunction);
}

int main(int argc, char **argv)
{
	if(argc > 1){
        // Definimos el tamaño del array previamente contando el número de parámetros que introduce el usuario
        int array_length = argc - 1;
        int *array;

        // Le asignamos al array un espacio en memoria igual al tamaño de un entero * el número de argumentos
        array = (int *)malloc(array_length * sizeof(int));

        // Paso el tamaño de la lista como puntero para que si hay algún no entero este se pueda modificar
		readArgs(&array_length, argv, array);
        printArray(array_length, array);
        ordenarIntArray(array_length, array);
        printArray(array_length, array);

	}else{
		printf("No se pasaron argumentos\n");
        printf("El array: []\n");
	}
	
	return 0;
}
