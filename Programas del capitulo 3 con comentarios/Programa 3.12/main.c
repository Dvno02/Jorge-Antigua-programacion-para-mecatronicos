#include <stdio.h>
#include <math.h>


/* Serie de ULAM.
El programa, al recibir como dato un entero positivo, obtiene y escribe la serie de ULAM.
NUM: variable de tipo entero. */

void main(void)
{
    int NUM;
    printf("Ingrese el numero para calcular la serie:");
    scanf("%d",&NUM);
    if (NUM > 0)
    {
        printf("\nSerie de ULAN\n");
        printf("%d \t", NUM);
        while (NUM != 1)
        {
            if (pow(-1, NUM) >0)
                NUM = NUM / 2;
            else
                NUM = NUM * 3 + 1;
            printf("%d\t", NUM);
        }
    }
    else
        printf("\n NUM debe ser un entero prositivo");
}


//While aqui continua mientras el valor de NUM sea diferente a 1, su funcion es calcular la serie de ULAM para un numero ingresado, ULAM es una secuencia de numeros en la que cada numero es el doble del numero anterior si es par, y si es impar el triple
