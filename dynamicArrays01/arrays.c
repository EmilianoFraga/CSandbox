#include <stdio.h>
#include <malloc.h>

void doDynamic1();
void doDynamic2();
void printDynamicArray(int**, int, int, int);

int main (int argc, char** argv) {
    doDynamic1();

    doDynamic2();

    return 0;
}

void doDynamic1 () {
    int** dynamicArray;

    dynamicArray = malloc(sizeof(int*) * 2);

    dynamicArray[0] = malloc(sizeof(int) * 2);

    dynamicArray[0][0] = 5;
    dynamicArray[0][1] = 7;

    // row 1 points to row 0, that is, they will share the same content
    // If row[1] changes, so does row[0] and vice-versa
    dynamicArray[1] = dynamicArray[0];

    dynamicArray[1][0] = 6;
    dynamicArray[1][1] = 8;

    printDynamicArray(dynamicArray, 1, 2, 2);

    free(dynamicArray[0]);
    free(dynamicArray);
}

void doDynamic2 () {
    int** dynamicArray;

    dynamicArray = malloc(sizeof(int*) * 2);

    dynamicArray[0] = malloc(sizeof(int) * 2);

    dynamicArray[0][0] = 5;
    dynamicArray[0][1] = 7;

    // row 1 has its own memory space, so it has distinct content from row 0
    // If row[1] changes this does not affect row[0] and vice-versa
    dynamicArray[1] = malloc(sizeof(int) * 2);

    dynamicArray[1][0] = 6;
    dynamicArray[1][1] = 8;

    printDynamicArray(dynamicArray, 2, 2, 2);

    free(dynamicArray[1]);
    free(dynamicArray[0]);
    free(dynamicArray);
}

void printDynamicArray(int **dynamicArray, int arrayUsageNumber, int rowCount, int colCount) {
    int r, c;

    printf("Dynamic Array usage %d\n", arrayUsageNumber);
    
    for (r = 0; r < rowCount; r++) {
        for (c = 0; c < colCount; c++) {
            printf ("dynamic[%d][%d] = %d\n", r, c, dynamicArray[r][c]);
        }// for c
    }// for r
    
    printf("\n");
}
