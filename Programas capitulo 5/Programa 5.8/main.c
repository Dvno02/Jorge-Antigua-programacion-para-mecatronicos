#include <stdio.h>

/* Primos.
El programa almacena en un arreglo unidimensional los primeros 100 números primos. */

const int TAM = 100;

void Imprime(int[], int); /* Prototipos de funciones. */
void Primo(int, int *);

int main(void)
{
    int P[TAM] = {2};
    int FLA, J = 1, PRI = 3;
    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA); /* Se llama a la función que determina si PRI es primo. */
        if (FLA) /* Si FLA es 1, entonces PRI es primo. */
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2;
    }
    Imprime(P, TAM);

    return 0;
}

void Primo(int A, int *B)
{
    int DI = 3;
    while (*B && (DI * DI <= A))
    {
        if ((A % DI) == 0)
            *B = 0;
        DI += 2; // Optimize by checking only odd divisors.
    }
}

void Imprime(int Primos[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nPrimos[%d]: %d", I, Primos[I]);
}
