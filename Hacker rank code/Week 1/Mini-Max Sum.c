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

// Function to split the input line into integers
void split(char* str, int* arr, int* count) {
    int idx = 0;
    char* token = strtok(str, " ");
    while (token != NULL && idx < 5) {
        arr[idx++] = atoi(token);
        token = strtok(NULL, " ");
    }
    *count = idx;
}

// Function to calculate and print the mini and max sum
void miniMaxSum(int* arr, int n) {
    long total = 0;
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < n; i++) {
        total += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("%ld %ld\n", total - max, total - min);
}

int main() {
    char input_line[100];
    fgets(input_line, sizeof(input_line), stdin);

    rtrim(input_line);
    int arr[5];
    int count = 0;

    split(input_line, arr, &count);

    if (count != 5) {
        fprintf(stderr, "Error: Please enter exactly 5 integers.\n");
        return 1;
    }

    miniMaxSum(arr, count);

    return 0;
}
