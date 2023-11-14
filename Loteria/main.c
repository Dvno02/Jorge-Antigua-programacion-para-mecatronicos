#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funci�n para generar un n�mero aleatorio entre un rango espec�fico
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Funci�n para mostrar el historial de tiradas
void mostrarHistorial(FILE *historialArchivo) {
    rewind(historialArchivo); // Regresar al principio del archivo
    printf("Historial de tiradas:\n");
    char linea[256];
    while (fgets(linea, sizeof(linea), historialArchivo)) {
        printf("%s", linea);
    }
}

int main() {
    srand(time(NULL));

    char opcion;
    int numero1, numero2, numero3;  // Declarar las variables fuera del switch

    FILE *historialArchivo = fopen("historial.txt", "a+"); // Abierto para lectura y escritura, creando el archivo si no existe

    if (historialArchivo == NULL) {
        printf("Error al abrir el archivo para guardar el historial.\n");
        return 1;
    }

    do {
        printf("Bienvenido a la Loter�a MJW\n");
        printf("1. Tirar 3 n�meros aleatorios\n");
        printf("2. Mostrar historial de tiradas\n");
        printf("3. Salir\n");
        printf("Elija una opci�n: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                numero1 = generarNumeroAleatorio(0, 99);
                numero2 = generarNumeroAleatorio(0, 99);
                numero3 = generarNumeroAleatorio(0, 99);
                time_t current_time;
                time(&current_time);

                fprintf(historialArchivo, "Tirada: %d %d %d - Fecha y hora: %s", numero1, numero2, numero3, ctime(&current_time));
                printf("Tirada: %d %d %d\n", numero1, numero2, numero3);
                break;
            case '2':
                mostrarHistorial(historialArchivo);
                break;
            case '3':
                printf("Saliendo del programa. Cerrando el archivo...\n");
                fclose(historialArchivo);
                break;
            default:
                printf("Opci�n no v�lida. Int�ntelo de nuevo.\n");
        }
    } while (opcion != '3');

    return 0;
}
