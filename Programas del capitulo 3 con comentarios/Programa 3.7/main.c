#include <stdio.h>
#include <stdlib.h>

/* Lanzamiento de martillo.
El programa, al recibir como dato N lanzamientos de martillo, calcula el promedio de los lanzamientos de la atleta cubana.

I, N: variables de tipo entero.
LAN, SLA: variables de tipo real. */

void main(void)
{
    int I, N;
    float LAN, SLA = 0;
    do
    {
        printf("Ingrese el número de lanzamiento:\t");
        scanf("%d", &N);
    }
    while (N < 1 || N > 11);
    /* Se utiliza la estructura do-while para verificar que el valor de N sea correcto. */
    for (I=1; I<=N; I++)
    {
        printf("\nIngrse el lazamiento %d:", I);
        scanf("%f", &LAN);
        SLA = SLA + LAN;
    }
    SLA = SLA / N;
    printf("\nEl promedio de lazamientos es: %.2f", SLA);
}


//For se utiliza para recorrer cada uno de los lanzamientos ingresados, comienza con I = 1 hasta que I sea igual a N
//Do-while se utiliza para solicitar que se ingrese el numero de lanzamiento, este continua solicitando una entrada hasta que se de un numero que este entre el 1 y el 11
