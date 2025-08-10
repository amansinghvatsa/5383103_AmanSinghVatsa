#include <stdio.h>
#include <stdlib.h> // for abs()

int diagonalDifference(int n, int arr[n][n]) {
    int primarySum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++) {
        primarySum += arr[i][i];
        secondarySum += arr[i][n - i - 1];
    }

    return abs(primarySum - secondarySum);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int result = diagonalDifference(n, arr);
    printf("%d\n", result);

    return 0;
}
