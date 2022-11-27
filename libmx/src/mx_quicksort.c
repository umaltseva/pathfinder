#include "../inc/libmx.h"
#include <stdio.h>

static void swap(char **a, char **b) {
    char* temp = *a;

    *a = *b;
    *b = temp;
}


int mx_quicksort(char **arr, int left, int right) {
    int swaps = 0;

    if (arr == NULL) {
        return -1;
    }
    
    if (left < right) {
        int j = right;
        int k = left;
        
        char *pivot = arr[(k + j) / 2];

        while (k <= j) {
            while (mx_strlen(arr[k]) < mx_strlen(pivot)) {
                k++;
            }
            while (mx_strlen(arr[j]) > mx_strlen(pivot)) {
                j--;
            }
            if (k <= j) {
                if (mx_strlen(arr[j]) != mx_strlen(arr[k])) {
                  swap(&arr[k], &arr[j]);
                    swaps = swaps + 1;
                }
                j--;
                k++;
            }
        }
        swaps += mx_quicksort(arr, left, j);
        swaps += mx_quicksort(arr, k, right);
    }
    return swaps;
}



