#include <stdio.h>

int birthday(int s[], int n, int d, int m) {
    int count = 0;
    int sum = 0;

    // Sum of first m elements
    for (int i = 0; i < m; i++) {
        sum += s[i];
    }
    if (sum == d) count++;

    // Sliding window
    for (int i = m; i < n; i++) {
        sum = sum - s[i - m] + s[i]; // move window
        if (sum == d) count++;
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int s[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    int d, m;
    scanf("%d %d", &d, &m);

    printf("%d\n", birthday(s, n, d, m));

    return 0;
}
