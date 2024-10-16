#include "Quick_Sort/quickSort.h"

void swap(float *p1, float *p2);

/**
 * Use quick sort algorithm to sort array of float pointers such that their pointed values are incresing order.
 *
 * @param *a[] - array of float pointers.
 * @param left - the start index of float pointer in array.
 * @param right - the end index of float pointer in array
 */
void quick_sort_inc(float *a[], int left, int right) {
// your code

    if (left >= right) {
        return;
    }
    int pivot_index = (left + right) / 2;
    float *pivot = a[pivot_index];
    int i = left;
    int j = right;
    while (i <= j) {
        while (*(a[i]) < *pivot) {
            i++;
        }
        while (*(a[j]) > *pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    quick_sort_inc(a, left, j);
    quick_sort_inc(a, i, right);
}
// helper function
void swap(float *p1, float *p2) {
    float temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}