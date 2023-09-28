#include <stdio.h>
#include <stdlib.h>

/*Nómina
El programa, al recibir los salarios de 15 profesores, obtiene el total de la nómina de la universidad.

I: variable de tipo entero.
SAL y NOM: variable de tipo real. */

void main(void)
{
    int I;
    float SAL, NOM;
    NOM = 0;
    for(I=1; I<=15; I++)
    {
        printf("\Ingrese el salario del profesor%d:\t", I);
        scanf("%f", &SAL);
        NOM = NOM + SAL;
    }
    printf("\nEl total de la nómina es: %.2f", NOM);
}


// For nos dice que I es igual a 1 y continua hasta que sea menor o igual a 15 y se incrementa en 1, se utiliza para recopilar los salarios que tienen los 15 profesores y calcular la nomina de la universidad.
