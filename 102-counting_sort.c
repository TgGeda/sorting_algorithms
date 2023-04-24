#include "sort.h"
#include <stdio.h>
/**
 *_calloc - this is a calloc function
 *@nmemb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, size_t size) {
    int max = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    int *count = (int *) malloc((max + 1) * sizeof(int));
    if (count == NULL) {
        printf("Error: Failed to allocate memory for count array\n");
        return;
    }
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    for (size_t i = 0; i < size; i++) {
        count[array[i]]++;
    }
    printf("Count array: ");
    for (int i = 0; i <= max; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");
    int index = 0;
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            array[index] = i;
            index++;
        }
    }
    free(count);
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    counting_sort(arr, size);
    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
