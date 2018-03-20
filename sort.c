#include "sort.h"





void bubble_sort(int *array, int length) {
    
    int temp;

    for(int i = 0; i < length; i++) {
        for(int j = i; j < length; j++) {
            if(array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}





void merge(int *A, int n, int m) {
    int i = 0;
    int j = m;
    int *B = (int *)malloc(n * sizeof(int));
    for(int k = 0; k < n; k++) {
        if(j >= n) {
            B[k] = A[i];
            i++;
        } else if(i >= m) {
            B[k] = A[j];
            j++;
        } else if(A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
    }

    for(int k = 0; k < n; k++) {
        A[k] = B[k];
    }
}

void merge_sort(int *array, int length) {
    if(length <= 1) {
        return;
    }
    else {
        int m = length/2;
        merge_sort(array, m);
        merge_sort(array + m, length - m);
        merge(array, length, m);
    }
}





void print_array(int *array, int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
    printf("\n");
}

