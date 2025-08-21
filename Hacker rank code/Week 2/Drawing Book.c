#include <stdio.h>

int pageCount(int n, int p) {
    int frontone = p / 2;
    int backone = (n / 2) - (p / 2);
    return (frontone < backone) ? frontone : backone;
}

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    int result = pageCount(n, p);
    printf("%d\n", result);

    return 0;
}
