#include <stdio.h>
#include <ctype.h>  // for tolower()
#include <string.h> // for strlen()

char* pangrams(char s[]) {
    int letters[26] = {0}; // track letters a-z
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower(s[i]);
        if (c >= 'a' && c <= 'z') {
            int index = c - 'a';
            if (letters[index] == 0) { 
                letters[index] = 1;
                count++;
            }
        }
    }

    if (count == 26)
        return "pangram";
    else
        return "not pangram";
}

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin); // read full line (including spaces)

    // Remove trailing newline from fgets
    s[strcspn(s, "\n")] = 0;

    printf("%s\n", pangrams(s));

    return 0;
}
