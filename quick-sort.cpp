#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int *arr, int left, int right){
    if(left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while(i <= j){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

void print_array(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    srand(time(NULL));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 101;
    }
    printf("Vetor desordenado: ");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);
    printf("Vetor ordenado: ");
    print_array(arr, n);

    return 0;
}