#include <stdio.h>

int sockMerchant(int n, int ar[]) {
    int count[101] = {0}; // assuming colors are between 1 and 100
    int pairs = 0;

    // Count socks by color
    for (int i = 0; i < n; i++) {
        count[ar[i]]++;
    }

    // Calculate pairs
    for (int i = 0; i < 101; i++) {
        pairs += count[i] / 2;
    }

    return pairs;
}

int main() {
    int n;
    scanf("%d", &n);
    int ar[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    printf("%d\n", sockMerchant(n, ar));
    return 0;
}
