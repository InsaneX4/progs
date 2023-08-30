//Write a program to find out the second smallest and second largest
//element stored in an array of n integers.
#include <stdio.h>
#include <limits.h>

void find_second_smallest_largest(int arr[], int n, int *second_smallest, int *second_largest) {
    if (n < 2) {
        *second_smallest = *second_largest = INT_MAX;
        return;
    }

    int smallest = INT_MAX;
    *second_smallest = INT_MAX;
    int largest = INT_MIN;
    *second_largest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            *second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < *second_smallest && arr[i] != smallest) {
            *second_smallest = arr[i];
        }

        if (arr[i] > largest) {
            *second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > *second_largest && arr[i] != largest) {
            *second_largest = arr[i];
        }
    }
}

int main() {
    int arr[] = {12, 45, 1, 78, 3, 6, 34, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    int second_smallest, second_largest;
    find_second_smallest_largest(arr, n, &second_smallest, &second_largest);

    printf("Second Smallest: %d\n", second_smallest);
    printf("Second Largest: %d\n", second_largest);

    return 0;
}
