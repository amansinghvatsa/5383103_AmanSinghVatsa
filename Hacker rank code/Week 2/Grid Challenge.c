#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare characters for qsort
int cmpChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Function to solve gridChallenge
char* gridChallenge(char grid[][101], int n) {
    // Step 1: Sort each row
    for (int i = 0; i < n; i++) {
        qsort(grid[i], strlen(grid[i]), sizeof(char), cmpChar);
    }

    // Step 2: Check columns
    int len = strlen(grid[0]);
    for (int col = 0; col < len; col++) {
        for (int row = 0; row < n - 1; row++) {
            if (grid[row][col] > grid[row + 1][col]) {
                return "NO";
            }
        }
    }

    return "YES";
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char grid[100][101]; // assuming max 100 rows, 100 chars per row
        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }

        printf("%s\n", gridChallenge(grid, n));
    }

    return 0;
}
