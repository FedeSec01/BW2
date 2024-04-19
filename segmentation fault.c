#include <stdio.h>

#define SIZE 10

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int vector[-1]; // Segmentation fault

    printf("Inserire %d interi:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("Il vettore inserito e':\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: %d\n", i + 1, vector[i]);
    }

    bubbleSort(vector, SIZE);

    printf("Il vettore ordinato e':\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: %d\n", i + 1, vector[i]);
    }

    return 0;
}