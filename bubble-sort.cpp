#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int Vet[10];
    int n = 10;
    
    srand(time(NULL));
//--------------------------------------
    for (int i = 0; i < n; i++){

        Vet[i] = rand() % 101;

    }
//--------------------------------------
    printf("Vetor desordenado: ");

    for (int i = 0; i < n; i++){

        printf("[%d]  ", Vet[i]);

    }
//--------------------------------------   
    printf("\n");

    bubbleSort(Vet, n);
//--------------------------------------
    printf("Vetor ordenado: ");

    for (int i = 0; i < n; i++){

        printf("[%d] ", Vet[i]);

    }
//--------------------------------------


    printf("\n");

    return 0;
}