#include <stdio.h>
#include <stdlib.h>

// Compare functions for qsort
int cmpAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int cmpDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

char* twoArrays(int n, int k, int A[], int B[]) {
    // Sort A ascending
    qsort(A, n, sizeof(int), cmpAsc);
    // Sort B descending
    qsort(B, n, sizeof(int), cmpDesc);

    // Check condition
    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int A[n], B[n];
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        for (int i = 0; i < n; i++) scanf("%d", &B[i]);

        printf("%s\n", twoArrays(n, k, A, B));
    }

    return 0;
}
