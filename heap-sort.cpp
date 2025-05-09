#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heap(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heap(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heap(arr, i, 0);
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

    heapSort(Vet, n);

    printf("Vetor ordenado: ");
    printArray(Vet, n);

    free(Vet);
    return 0;
}