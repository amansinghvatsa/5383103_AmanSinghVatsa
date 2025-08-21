#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

// Initialize a vector
void initVector(Vector *v) {
    v->size = 0;
    v->capacity = 2;
    v->data = (int *)malloc(v->capacity * sizeof(int));
}

// Append to vector
void pushBack(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

// Free vector memory
void freeVector(Vector *v) {
    free(v->data);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Create n sequence lists
    Vector *arr = (Vector *)malloc(n * sizeof(Vector));
    for (int i = 0; i < n; i++) {
        initVector(&arr[i]);
    }

    int lastAnswer = 0;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            // Append y to arr[idx]
            pushBack(&arr[idx], y);
        } else if (type == 2) {
            int value = arr[idx].data[y % arr[idx].size];
            lastAnswer = value;
            printf("%d\n", lastAnswer);
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        freeVector(&arr[i]);
    }
    free(arr);

    return 0;
}
