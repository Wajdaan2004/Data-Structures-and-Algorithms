#include "Selection_Sort/selectionSort.h"

void swap(float *p1, float *p2);

/**
 * Use selection sort algorithm to sort array of float pointers such that their pointed values are incresing order.
 *
 * @param *a[] - array of float pointers.
 * @param left - the start index of float pointer in array.
 * @param right - the end index of float pointer in array
 */
void select_sort_inc(float *a[], int left, int right) {
// your code

    for (int i = left; i <= right; i++) {
        int min_index = i;
        for (int j = i + 1; j <= right; j++) {
            if (*(a[j]) < *(a[min_index])) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(a[i], a[min_index]);
        }
    }
}

// helper function
void swap(float *p1, float *p2) {
    float temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}