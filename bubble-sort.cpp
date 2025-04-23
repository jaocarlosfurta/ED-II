#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int troca = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                troca = 1;
            }
        }
        if (troca == 0){
            break;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *Vet = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        Vet[i] = rand() % 101;
    }

    printf("Vetor desordenado: ");
    printArray(Vet, n);

    bubbleSort(Vet, n);

    printf("Vetor ordenado: ");
    printArray(Vet, n);

    free(Vet);
    return 0;
}