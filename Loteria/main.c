#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar un número aleatorio entre un rango específico
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Función para mostrar el historial de tiradas
void mostrarHistorial(FILE *historialArchivo) {
    rewind(historialArchivo); // Regresar al principio del archivo
    printf("Historial de tiradas:\n");
    char linea[256];
    while (fgets(linea, sizeof(linea), historialArchivo)) {
        printf("%s", linea);
    }
}

// Función para realizar una tirada y guardarla en el historial
void realizarTirada(FILE *historialArchivo, int tipoJuego, int *numerosElegidos, float *saldo) {
    int numero1, numero2, numero3;
    time_t current_time;
    time(&current_time);

    float apuesta;
    printf("Ingresa la cantidad de dinero a apostar: ");
    scanf("%f", &apuesta);

    switch (tipoJuego) {
    case 1: // Tirar 3 números aleatorios
        numero1 = generarNumeroAleatorio(0, 99);
        numero2 = generarNumeroAleatorio(0, 99);
        numero3 = generarNumeroAleatorio(0, 99);
        break;
    case 2: // Jugar un número
        numero1 = generarNumeroAleatorio(0, 99);
        numero2 = generarNumeroAleatorio(0, 99);
        numero3 = generarNumeroAleatorio(0, 99);
        break;
    case 3: // Jugar un pale
        numero1 = generarNumeroAleatorio(0, 99);
        numero2 = generarNumeroAleatorio(0, 99);
        numero3 = generarNumeroAleatorio(0, 99);
        break;
    case 4: // Jugar una tripleta
        numero1 = generarNumeroAleatorio(0, 99);
        numero2 = generarNumeroAleatorio(0, 99);
        numero3 = generarNumeroAleatorio(0, 99);
        break;
    default:
        printf("Opción de juego no válida.\n");
        return;
    }

    fprintf(historialArchivo, "Tirada: %d %d %d - Apuesta: %.2f pesos - Fecha y hora: %s", numero1, numero2, numero3, apuesta, ctime(&current_time));

    // Imprimir en consola los resultados
    if (tipoJuego == 1) {
        printf("Tirada: %d %d %d\n", numero1, numero2, numero3);
    } else {
        printf("Tus números: %d %d %d - Números de la Lotería: %d %d %d\n", numerosElegidos[0], numerosElegidos[1], numerosElegidos[2], numero1, numero2, numero3);

        // Verificar si los números jugados coinciden con la lotería
        if (numerosElegidos[0] == numero1 && numerosElegidos[1] == numero2 && numerosElegidos[2] == numero3) {
            float ganancias = apuesta * 50; // Multiplicar la cantidad apostada por 50 en caso de acertar
            *saldo += ganancias;
            printf("¡Felicidades! Has ganado %.2f pesos. Saldo actual: %.2f pesos.\n", ganancias, *saldo);
        } else {
            *saldo -= apuesta; // Restar la cantidad apostada al saldo en caso de no acertar
            printf("Lo siento, no has ganado en esta tirada. Saldo actual: %.2f pesos.\n", *saldo);
        }
    }
}

int main() {
    srand(time(NULL));

    char opcion;
    int tipoJuego, numerosElegidos[3];
    float saldo = 0.0;

    FILE *historialArchivo = fopen("historial3.txt", "a+"); // Abierto para lectura y escritura, creando el archivo si no existe

    if (historialArchivo == NULL) {
        perror("Error al abrir el archivo para guardar el historial");
        return 1;
    }

    do {
        printf("\nBienvenido a la Lotería MJW\n");
        printf("1. Tirar 3 números aleatorios\n");
        printf("2. Jugar un número\n");
        printf("3. Jugar un pale\n");
        printf("4. Jugar una tripleta\n");
        printf("5. Mostrar historial de tiradas\n");
        printf("6. Salir\n");
        printf("Elija una opción: ");
        scanf(" %c", &opcion);

        switch (opcion) {
        case '1':
            realizarTirada(historialArchivo, 1, NULL, &saldo); // Tipo de juego 1: Tirar 3 números aleatorios, númerosElegidos no se utiliza
            break;
        case '2':
            printf("Ingrese el número a jugar: ");
            scanf("%d", &numerosElegidos[0]);
            realizarTirada(historialArchivo, 2, numerosElegidos, &saldo); // Tipo de juego 2: Jugar un número
            break;
        case '3':
            printf("Ingrese el primer número del pale: ");
            scanf("%d", &numerosElegidos[0]);
            printf("Ingrese el segundo número del pale: ");
            scanf("%d", &numerosElegidos[1]);
            realizarTirada(historialArchivo, 3, numerosElegidos, &saldo); // Tipo de juego 3: Jugar un pale
            break;
        case '4':
            printf("Ingrese el primer número de la tripleta: ");
            scanf("%d", &numerosElegidos[0]);
            printf("Ingrese el segundo número de la tripleta: ");
            scanf("%d", &numerosElegidos[1]);
            printf("Ingrese el tercer número de la tripleta: ");
            scanf("%d", &numerosElegidos[2]);
            realizarTirada(historialArchivo, 4, numerosElegidos, &saldo); // Tipo de juego 4: Jugar una tripleta
            break;
        case '5':
            mostrarHistorial(historialArchivo);
            break;
        case '6':
            printf("Saliendo del programa. Cerrando el archivo...\n");
            fclose(historialArchivo);
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != '6');

    return 0;
}
