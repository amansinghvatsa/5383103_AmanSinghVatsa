#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparator for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxMin(int k, int arr[], int n) {
    // Sort the array
    qsort(arr, n, sizeof(int), cmpfunc);

    int minUnfairness = INT_MAX;

    // Check each window of size k
    for (int i = 0; i <= n - k; i++) {
        int diff = arr[i + k - 1] - arr[i];
        if (diff < minUnfairness) {
            minUnfairness = diff;
        }
    }

    return minUnfairness;
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxMin(k, arr, n);
    printf("%d\n", result);

    free(arr);
    return 0;
}
