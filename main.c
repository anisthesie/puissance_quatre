#include <stdio.h>

int readNumberAndCheckIfValid(int min, int max) {
    int number;
    scanf("%d", &number);
    while (number < min || number > max) {
        printf("Invalid number. Please try again: ");
        scanf("%d", &number);
    }
    return number;
}

int maian() {


    return 0;
}
