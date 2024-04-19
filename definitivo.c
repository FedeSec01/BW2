#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define BUFFER_OVERFLOW_SIZE 15

void inputVector(int vector[], int size) {
    printf("Inserire %d interi:\n", size);
    for (int i = 0; i < size; i++) {
        int input;
        bool validInput = false;
        do {
            printf("[%d]: ", i + 1);
            if (scanf("%d", &input) != 1) {
                // Pulizia del buffer di input in caso di errore di input
                while (getchar() != '\n');
                printf("Input non valido. Inserire un numero intero.\n");
            } else {
                validInput = true;
            }
        } while (!validInput);
        vector[i] = input;
    }

    // Se l'utente inserisce più di 10 valori, effettua il buffer overflow
    if (size > SIZE) {
        printf("Buffer overflow! Verranno ordinati solo i primi %d valori.\n", SIZE);
    }
}


void printVector(int vector[], int size) {
    printf("Il vettore inserito e':\n");
    for (int i = 0; i < size; i++) {
        printf("[%d]: %d\n", i + 1, vector[i]);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printSortedVector(int vector[], int size) {
    bubbleSort(vector, size);
    printf("Il vettore ordinato e':\n");
    for (int i = 0; i < size; i++) {
        printf("[%d]: %d\n", i + 1, vector[i]);
    }
}

void menu() {
    printf("Menu:\n");
    printf("1. Esegui il programma correttamente\n");
    printf("2. Buffer Overflow\n");
    printf("3. Esci\n");
}

int main() {
    int choice;
    int *vector = (int*)malloc(SIZE * sizeof(int));
    if (vector == NULL) {
        printf("Errore di allocazione di memoria.\n");
        return -1;
    }
    do {
        menu();
        printf("Scelta: ");
        if (scanf("%d", &choice) != 1) {
            // Pulizia del buffer di input in caso di errore di input
            while (getchar() != '\n');
            printf("Input non valido. Inserire un numero intero.\n");
            continue;
        }
        switch (choice) {
            case 1:
                inputVector(vector, SIZE);
                printVector(vector, SIZE);
                printSortedVector(vector, SIZE);
                break;
            case 2:
                inputVector(vector, BUFFER_OVERFLOW_SIZE);
                printVector(vector, BUFFER_OVERFLOW_SIZE);
                printSortedVector(vector, BUFFER_OVERFLOW_SIZE);
                break;
            case 3:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
                break;
        }
    } while (choice != 3);
    free(vector);
    return 0;}
