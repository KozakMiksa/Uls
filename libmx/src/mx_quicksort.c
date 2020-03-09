#include "libmx.h"

static void swap(char ***a, int *low, int *high, int *count) {
    char **arr = *a;

    if (mx_strlen(arr[*low]) > mx_strlen(arr[*high])) {
        (*count)++;
        mx_swap_str(&arr[*low], &arr[*high]);
    }
    (*low)++;
    (*high)--;
}

int mx_quicksort(char **arr, int left, int right) {
    int count = 0;
    int low = left;
    int high = right;
    int pivot = (high + low) / 2;

    if (arr == NULL || *arr == NULL)
        return -1;
    if (left < right) {
        while (low <= high) {
            for (; mx_strlen(arr[low]) < mx_strlen(arr[pivot]); low++);
            for (; mx_strlen(arr[high]) > mx_strlen(arr[pivot]); high--);
            if (low <= high)
                swap(&arr, &low, &high, &count);
        }
        count += mx_quicksort(arr, left, high);
        count += mx_quicksort(arr, low, right);
    }
    return count;
}
