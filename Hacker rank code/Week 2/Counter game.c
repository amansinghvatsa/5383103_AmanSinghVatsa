#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to check if n is power of 2
bool isPowerOfTwo(unsigned long long n) {
    return (n && !(n & (n - 1)));
}

// Function to find largest power of 2 less than n
unsigned long long largestPowerOfTwo(unsigned long long n) {
    unsigned long long p = 1ULL << ((unsigned long long)log2(n));
    return p;
}

void counterGame(unsigned long long n) {
    int moves = 0;
    while (n > 1) {
        if (isPowerOfTwo(n)) {
            n /= 2;
        } else {
            n -= largestPowerOfTwo(n);
        }
        moves++;
    }

    if (moves % 2 == 1)
        printf("Louise\n");
    else
        printf("Richard\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        counterGame(n);
    }
    return 0;
}
