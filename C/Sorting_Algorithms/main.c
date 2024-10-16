#include <stdio.h>
#include "Selection_Sort/selectionSort.h"
#include "Quick_Sort/quickSort.h"

int main() {
    // Array of float values
    float values[] = {3.4, 2.1, 5.7, 1.2, 4.9};
    
    // Array of pointers to float values
    float *ptr_arr[5];
    
    for (int i = 0; i < 5; i++) {
        ptr_arr[i] = &values[i];
    }

    // Print original array
    printf("Original array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", *ptr_arr[i]);
    }
    printf("\n");

    // Test Selection Sort
    select_sort_inc(ptr_arr, 0, 4);
    printf("\nArray after Selection Sort:\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", *ptr_arr[i]);
    }
    printf("\n");

    // Reset array to unsorted state
    float values2[] = {3.4, 2.1, 5.7, 1.2, 4.9};
    for (int i = 0; i < 5; i++) {
        ptr_arr[i] = &values2[i];
    }

    // Test Quick Sort
    quick_sort_inc(ptr_arr, 0, 4);
    printf("\nArray after Quick Sort:\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", *ptr_arr[i]);
    }
    printf("\n");

    return 0;
}

