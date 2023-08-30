#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l, int m, int h, int *comparisonCount, int order) {
    int i = l;
    int j = m + 1;
    int k = 0;
    int b[h - l + 1];

    while (i <= m && j <= h) {
        (*comparisonCount)++;
        if ((order == 1 && a[i] < a[j]) || (order == 2 && a[i] >= a[j])) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= h) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int x = 0; x < k; x++) {
        a[l + x] = b[x];
    }
}

void mergeSort(int arr[], int l, int r, int *comparisonCount, int order) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, comparisonCount, order);
        mergeSort(arr, m + 1, r, comparisonCount, order);

        merge(arr, l, m, r, comparisonCount, order);
    }
}

int main() {
    int choice;
    char *inputFileName, *outputFileName;

    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        int order;
        if (choice == 1) {
            inputFileName = "inAsce.txt";
            outputFileName = "outMergeAsce.txt";
            order = 1;
        } else if (choice == 2) {
            inputFileName = "inDesc.txt";
            outputFileName = "outMergeDesc.txt";
            order = 2;
        } else if (choice == 3) {
            inputFileName = "inRand.txt";
            outputFileName = "outMergeRand.txt";
            order = 1; // Default to ascending for random data
        } else {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        FILE *inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL) {
            printf("Error opening input file.\n");
            return 1;
        }

        int n;
        printf("Enter the number of elements to be sorted: ");
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++) {
            fscanf(inputFile, "%d", &arr[i]);
        }

        fclose(inputFile);

        clock_t start_time = clock();
        int comparisonCount = 0;
        mergeSort(arr, 0, n - 1, &comparisonCount, order);
        clock_t end_time = clock();

        FILE *outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL) {
            printf("Error opening output file.\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            fprintf(outputFile, "%d ", arr[i]);
        }

        fclose(outputFile);

        double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Sorting completed and written to %s\n", outputFileName);
        printf("Number of comparisons: %d\n", comparisonCount);
        printf("Execution time: %f seconds\n", execution_time);
    }

    return 0;
}
