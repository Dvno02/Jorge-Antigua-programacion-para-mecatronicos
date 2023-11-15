#include <stdio.h>
/* Alumnos.
El programa pregunta al usuario el número de registro que desea
➥modificar, obtiene el nuevo promedio del alumno y modifica tanto el
➥registro como el archivo correspondiente. */
typedef struct /* Declaración de la estructura alumno. */
{
int matricula;
char nombre[20];
int carrera;
float promedio;
} alumno;
void modifica(FILE *); /* Prototipo de función. */
void main(void)
{
FILE *ar;
if ((ar = fopen ("ad1.dat", "r+")) != NULL)
modifica(ar);
else
printf("\nEl archivo no se puede abrir");
fclose(ar);
}
void modifica(FILE *ap)

{
int d;
alumno alu;
printf("\nIngrese el número de registro que desea modificar: ");
scanf("%d", &d);

fseek(ap, (d-1)*sizeof(alumno), 0);
fread(&alu, sizeof(alumno), 1, ap);
printf("\nIngrese el promedio correcto del alumno: ");
scanf("%f", &alu.promedio);
fseek(ap, (d-1)*sizeof(alumno), 0);
fwrite(&alu, sizeof(alumno), 1, ap);
}
