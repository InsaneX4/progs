#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 500

void insertionSort(int arr[], int n, int *comparisons) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*comparisons)++;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter your choice (1/2/3/4): ");
    scanf("%d", &choice);

    if (choice == 4) {
        printf("Exiting...\n");
        return 0;
    }

    int inputSize;
    printf("Enter the number of elements: ");
    scanf("%d", &inputSize);


    int inputElements[MAX_ELEMENTS];
    int comparisons = 0;

    char inputFilename[20];
    char outputFilename[20];

    switch (choice) {
        case 1: // Ascending Data
            strcpy(inputFilename, "inAsce.dat");
            strcpy(outputFilename, "outInsAsce.dat");
            break;
        case 2: // Descending Data
            strcpy(inputFilename, "inDesc.dat");
            strcpy(outputFilename, "outInsDesc.dat");
            break;
        case 3: // Random Data
            strcpy(inputFilename, "inRand.dat");
            strcpy(outputFilename, "outInsRand.dat");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    FILE *inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    for (int i = 0; i < inputSize; i++) {
        fscanf(inputFile, "%d", &inputElements[i]);
    }
    fclose(inputFile);

    printf("Before Sorting: Content of the input file\n");
    printArray(inputElements, inputSize);

    insertionSort(inputElements, inputSize, &comparisons);

    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < inputSize; i++) {
        fprintf(outputFile, "%d\n", inputElements[i]);
    }
    fclose(outputFile);

    printf("After Sorting: Content of the output file\n");
    printArray(inputElements, inputSize);

    printf("Number of Comparisons: %d\n", comparisons);

    if (comparisons == 0) {
        printf("Scenario: Best-case\n");
    } else if (comparisons == (inputSize * (inputSize - 1)) / 2) {
        printf("Scenario: Worst-case\n");
    } else {
        printf("Scenario: Between best and worst cases\n");
    }

    return 0;
}
