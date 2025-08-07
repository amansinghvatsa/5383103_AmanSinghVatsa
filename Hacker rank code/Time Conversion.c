#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void timeConversion(const char* s, char* result) {
    int hour, minute, second;
    char period[3]; 

    sscanf(s, "%2d:%2d:%2d%2s", &hour, &minute, &second, period);

    
    if (strcmp(period, "AM") == 0) {
        if (hour == 12)
            hour = 0; 
    } else {
        if (hour != 12)
            hour += 12; 
    }

    
    sprintf(result, "%02d:%02d:%02d", hour, minute, second);
}

int main() {
    char input[20];
    char result[10];

    
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 

    timeConversion(input, result);
    printf("%s\n", result);

    return 0;
}
