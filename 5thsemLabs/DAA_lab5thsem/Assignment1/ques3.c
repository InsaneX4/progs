#include <stdio.h>
#include <stdlib.h>

// Function to find the total number of duplicate elements
int count_duplicates(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break; // Increment count only once for each duplicate element
            }
        }
    }
    return count;
}

// Function to find the most repeating element
int find_most_repeating_element(int arr[], int n) {
    int max_count = 0;
    int most_repeating_element = arr[0];
    
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_repeating_element = arr[i];
        }
    }
    return most_repeating_element;
}

int main() {
    FILE *file;
    int n = 0;
    int i;
    const char filename[] = "input.txt"; // Replace "input.txt" with your file name

    // Read integers from the disc file and count the number of integers
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &i) != EOF) {
        n++;
    }

    // Close the file
    fclose(file);

    // Create an array to store the integers
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read integers from the file and store them in the array
    file = fopen(filename, "r");
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    // Close the file
    fclose(file);

    // Find the total number of duplicate elements
    int total_duplicates = count_duplicates(arr, n);
    printf("Total number of duplicate elements: %d\n", total_duplicates);

    // Find the most repeating element
    int most_repeating_element = find_most_repeating_element(arr, n);
    printf("Most repeating element: %d\n", most_repeating_element);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
