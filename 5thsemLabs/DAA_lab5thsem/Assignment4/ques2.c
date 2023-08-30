#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform partitioning for Quick Sort
int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

// Function to read input from file
int readFromFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
    return 1;
}

// Function to write output to file
void writeToFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main() {
    int choice;
    int size = 0;
    printf("Enter the number of elments");
    scanf("%d",&size);// Number of elements in each scenario
    int arr[size];
    int comparisons = 0;

    printf("Menu:\n");
    printf("1. Best-case input\n");
    printf("2. Average-case input\n");
    printf("3. Worst-case input\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (!readFromFile("best_case.txt", arr, size)) {
                return 1;
            }
            break;
        case 2:
            if (!readFromFile("average_case.txt", arr, size)) {
                return 1;
            }
            break;
        case 3:
            if (!readFromFile("worst_case.txt", arr, size)) {
                return 1;
            }
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    quickSort(arr, 0, size - 1, &comparisons);
    writeToFile("sorted_output.txt", arr, size);

    printf("Sorted elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of comparisons: %d\n", comparisons);

    if (comparisons == (size * (size - 1)) / 2) {
        printf("Best-case partitioning scenario.\n");
    } else if (comparisons == size * (size - 1)) {
        printf("Worst-case partitioning scenario.\n");
    }

    return 0;
}
