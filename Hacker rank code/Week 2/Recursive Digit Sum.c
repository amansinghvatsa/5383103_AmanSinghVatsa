#include <stdio.h>
#include <string.h>

// Helper function to compute sum of digits in a string
long long sumOfDigits(char *n) {
    long long sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        sum += (n[i] - '0');
    }
    return sum;
}

// Recursive function to calculate super digit
int superDigitCalc(long long num) {
    if (num < 10) return num; // Base case
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return superDigitCalc(sum);
}

// Main superDigit function
int superDigit(char *n, int k) {
    long long digitSum = sumOfDigits(n);
    long long total = digitSum * k;
    return superDigitCalc(total);
}

int main() {
    char n[100001];  // n can be very large
    int k;
    scanf("%s %d", n, &k);

    printf("%d\n", superDigit(n, k));
    return 0;
}
