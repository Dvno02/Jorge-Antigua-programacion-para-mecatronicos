#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int cont = 0;
    float x = 0.0;
    float b = 0.0;
    printf("Calculo de raiz caudrada\n");
    printf("Ingrese el numero:");
    scanf("%f",&x);

    b = x;
    cont = 0;
    while (!(b == (x/b)))
    {
        cont++;
        b = 0.5* ((x/b)+ b);
        printf("\nValor x: %f",x);
        printf("\nValor b: %f",b);
        printf("\nValor cont: %i",cont);
    }

    printf("\nLa raiz cuadrada de %f es: %f",x,b);
    return 0;
}
