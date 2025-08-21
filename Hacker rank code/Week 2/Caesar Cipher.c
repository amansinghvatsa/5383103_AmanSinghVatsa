#include <stdio.h>
#include <string.h>

void caesarCipher(char s[], int k) {
    int shift = ((k % 26) + 26) % 26;  // normalize shift to [0,25]
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            s[i] = 'a' + (c - 'a' + shift) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            s[i] = 'A' + (c - 'A' + shift) % 26;
        }
        // non-alphabetic characters remain unchanged
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    char s[10005];  // buffer (adjust if needed for constraints)
    scanf("%s", s);

    scanf("%d", &k);

    caesarCipher(s, k);

    printf("%s\n", s);

    return 0;
}
