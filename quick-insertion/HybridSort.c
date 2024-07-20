#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define THRESHOLD 10

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j <= right - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;
        int pi = i + 1;

        quicksort(arr, left, pi - 1);
        quicksort(arr, pi + 1, right);
    }
}

void hybridQuicksort(int arr[], int left, int right) {
    if (right - left + 1 <= THRESHOLD) {
        insertionSort(arr, left, right);
    } else {
        if (left < right) {
            int pivot = arr[right];
            int i = left - 1;
            for (int j = left; j <= right - 1; j++) {
                if (arr[j] < pivot) {
                    i++;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            int temp = arr[i + 1];
            arr[i + 1] = arr[right];
            arr[right] = temp;
            int pi = i + 1;

            hybridQuicksort(arr, left, pi - 1);
            hybridQuicksort(arr, pi + 1, right);
        }
    }
}

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Generates a random number between 0 and 9999
    }
}

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    int *arrCopy1 = (int *)malloc(size * sizeof(int));
    int *arrCopy2 = (int *)malloc(size * sizeof(int));

    generateRandomArray(arr, size);
    copyArray(arr, arrCopy1, size);
    copyArray(arr, arrCopy2, size);

    clock_t start, end;
    double time_taken;

    // Measure time for Insertion Sort
    start = clock();
    insertionSort(arr, 0, size - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %f seconds\n", time_taken);

    // Measure time for Quicksort
    start = clock();
    quicksort(arrCopy1, 0, size - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quicksort Time: %f seconds\n", time_taken);

    // Measure time for Hybrid Quicksort
    start = clock();
    hybridQuicksort(arrCopy2, 0, size - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Hybrid Quicksort Time: %f seconds\n", time_taken);

    free(arr);
    free(arrCopy1);
    free(arrCopy2);

    return 0;
}
