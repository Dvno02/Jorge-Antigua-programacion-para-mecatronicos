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
