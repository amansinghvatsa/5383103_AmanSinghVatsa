#include <stdio.h>
#include <stdlib.h>

int flippingMatrix(int matrix_rows, int matrix_columns, int** matrix) {
    int n = matrix_rows / 2;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = matrix[i][j];
            int b = matrix[i][matrix_columns - j - 1];
            int c = matrix[matrix_rows - i - 1][j];
            int d = matrix[matrix_rows - i - 1][matrix_columns - j - 1];

            int max_val = a;
            if (b > max_val) max_val = b;
            if (c > max_val) max_val = c;
            if (d > max_val) max_val = d;

            sum += max_val;
        }
    }
    return sum;
}

int main() {
    int q;  
    scanf("%d", &q); // number of test cases

    while (q--) {
        int n;
        scanf("%d", &n); // n is half the matrix size

        int size = 2 * n;
        int** matrix = (int**)malloc(size * sizeof(int*));
        for (int i = 0; i < size; i++) {
            matrix[i] = (int*)malloc(size * sizeof(int));
            for (int j = 0; j < size; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int result = flippingMatrix(size, size, matrix);
        printf("%d\n", result);

        for (int i = 0; i < size; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }

    return 0;
}
