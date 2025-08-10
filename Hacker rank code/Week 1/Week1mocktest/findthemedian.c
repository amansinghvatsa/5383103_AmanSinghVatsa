#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int findMedian(int arr_count, int* arr) {
    qsort(arr, arr_count, sizeof(int), compare);
    return arr[arr_count / 2];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", findMedian(n, arr));
    return 0;
}
