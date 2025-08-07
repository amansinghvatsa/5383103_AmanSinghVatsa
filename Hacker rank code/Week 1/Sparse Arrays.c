#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 100
#define MAX_N 1000
#define MAX_Q 1000

int main() {
    int n, q;
    char strings[MAX_N][MAX_STRING_LEN];
    char queries[MAX_Q][MAX_STRING_LEN];
    int results[MAX_Q] = {0};

    
    scanf("%d", &n);
    getchar(); 

   
    for (int i = 0; i < n; i++) {
        fgets(strings[i], sizeof(strings[i]), stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0'; 
    }

    
    scanf("%d", &q);
    getchar(); 

    
    for (int i = 0; i < q; i++) {
        fgets(queries[i], sizeof(queries[i]), stdin);
        queries[i][strcspn(queries[i], "\n")] = '\0'; 
    }

    
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                results[i]++;
            }
        }
    }

   
    for (int i = 0; i < q; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}
