#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    srand(time(NULL));
    int columna, f, c;
    int fila = 15;
    int **matriz;

    columna = (rand() %11) + 5;

    // Asigno memoria
    matriz = (int **) calloc(fila, sizeof(int *));
    for(f=0; f<fila; f++){
        matriz[f] = (int *) calloc(columna, sizeof(int));
    }
    
    // Guardo valores aleatorios en la matriz
    for(f=0;f<fila;f++){
        for(c=0;c<columna;c++){
            matriz[f][c]= (rand() %899) + 100;
        }
    }

    // Muestro la matriz
    for(f=0; f<fila; f++){
        for(c=0; c<columna; c++){
            printf("%d ", matriz[f][c]);
        }
        printf("\n");
    }

    // Apartado b)
    int *vector = (int *) calloc(15, sizeof(int));
    int numPares = 0;

    for(f=0; f<fila; f++){
        for(c=0; c<columna; c++){
            // Verifico que sea par
            if(matriz[f][c]%2 == 0){
                numPares++;
            }
            *(vector+f) = numPares;
        }
        numPares = 0;
    }

    // Muestro los numeros pares
    printf("\n\n");
    printf("Los numeros pares por fila de la matriz son: ");
    for(f=0; f<15; f++){
        printf("%d ",*(vector+f));
    }
    free(vector);

    // Libero la memoria
    for(f=0; f<fila; f++){
        free(matriz[f]);
    }
    free(matriz);

    getchar();
    return 0;
}