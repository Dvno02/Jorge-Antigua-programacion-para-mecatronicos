#include <stdio.h>
#include <stdlib.h>

/* Suma positivos.
El programa, al recibir como datos N números enteros, obtiene la suma de los enteros positivos.

I, N, NUM, SUM: variables de tipo entero. */

void main (void)
{
    int I, N, NUM, SUM;
    SUM = 0;
    printf("Ingrese el número de datos: \t");
    scanf("%d", &N);
    for (I=1; I<=N; I++)
    {
        printf("Ingrse el dato número %d:\t", I);
        scanf("%d", &NUM);
        if (NUM > 0)
            SUM = SUM + NUM;
    }
    printf("\nLa suma de los números positivos es: %d", SUM);
}


// For nos dice que I es igual a 1, continua hasta que sea menor o igual que N (N es el valor ingresado por el usuario) y va incrementando en 1, for compila los numeros entero y calcula la suma de los numeros positivos
