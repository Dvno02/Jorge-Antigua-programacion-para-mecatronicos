#include <stdio.h>
#include <stdlib.h>

/* Fibonacci.
El programa calcula  esccribe los primeros 50 muneors de fibonacci.

I, RPI, SEG: variable de tipo entero. */

void main(void)
{
    int I, PRI = 0, SEG = 1, SIG;
    printf("\t %d", PRI, SEG);
    for (I = 3; I <= 50; I++)
    {
        SIG = PRI + SEG;
        PRI = SEG;
        SEG = SIG;
        printf("\t %d", SIG);
    }
}


//For dice que I es igual a 3 y continua hasta que I sea menor o igual a 50, I se incrementa en 1, for calcula y escribe los primeros 50 numeros de Fibonacci
