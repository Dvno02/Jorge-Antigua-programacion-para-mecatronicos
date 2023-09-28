#include <stdio.h>
#include <math.h>

/* Suma de cuadrados.
El programa, al recibir como datos un grupo de enteros positivos, obtiene eñ cuadrado en los mismos y la suma correspondiente a dichos cuadrados. */

void main(void)
{
    int NUM;
    long CUA, SUC = 0;
    printf("\nIngrese un numero entero -0 para terminar -:\t");
    scanf("%d", &NUM);
    while(NUM)
    /* Observa que la condición es verdadera mientras el entero es diferente de cero. */
    {
        CUA = pow (NUM, 2);
        printf("%d al cubo es %ld", NUM, CUA);
        SUC = SUC + CUA;
        printf("\nIngrese un numero entero -0 para terminar -:\t");
    }
    printf("\nLa suma de los cuadrados es %ld", SUC);
}


//While se utiliza para compilar numeros enteros, calcular el cuadrado de cada numero y calcular la suma total de los cuadrados hasta que se ingrese el valor 0
