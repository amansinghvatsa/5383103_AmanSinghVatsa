#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to trim leading spaces
char* ltrim(char* str) {
    while (isspace(*str)) str++;
    return str;
}

// Function to trim trailing spaces
char* rtrim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

// Function to split the input string and fill the array
void split(char* str, int* arr, int* out_count) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        arr[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    *out_count = count;
}

// Function to calculate and print ratios
void plusMinus(int* arr, int n) {
    int pos = 0, neg = 0, zero = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) pos++;
        else if (arr[i] < 0) neg++;
        else zero++;
    }

    printf("%.6f\n", (float)pos / n);
    printf("%.6f\n", (float)neg / n);
    printf("%.6f\n", (float)zero / n);
}

int main() {
    char n_str[100];
    fgets(n_str, sizeof(n_str), stdin);
    int n = atoi(ltrim(rtrim(n_str)));

    char input_line[10000];
    fgets(input_line, sizeof(input_line), stdin);
    rtrim(input_line);

    int arr[1000];
    int count = 0;
    split(input_line, arr, &count);

    if (count != n) {
        fprintf(stderr, "Error: Expected %d numbers, but got %d.\n", n, count);
        return 1;
    }

    plusMinus(arr, n);

    return 0;
}

