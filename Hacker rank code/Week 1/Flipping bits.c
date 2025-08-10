#include <stdio.h>
#include <stdint.h> // for uint32_t

uint32_t flippingBits(uint32_t n) {
    return ~n; // bitwise NOT flips all bits
}

int main() {
    int q; // number of test cases
    scanf("%d", &q);

    while (q--) {
        uint32_t n;
        scanf("%u", &n);
        printf("%u\n", flippingBits(n));
    }

    return 0;
}
