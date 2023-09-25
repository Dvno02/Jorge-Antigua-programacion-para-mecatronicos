#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int entero = 0;
    float flotante = 0.0;
    double decimal = 0.0;
    char letra = 'a';
    long int lentero = 0;

    printf("\nMemoria ocupada en byte de entero %i",sizeof(entero));
    printf("\nMemoria ocupada en byte de flotante %i",sizeof(flotante));
    printf("\nMemoria ocupada en byte de double %i",sizeof(decimal));
    printf("\nMemoria ocupada en byte de caracter %i",sizeof(letra));
    printf("\nMemoria ocupada en byte de long %i",sizeof(lentero));

    printf("\nDireccion de memoria decimal %p", &decimal);
}
