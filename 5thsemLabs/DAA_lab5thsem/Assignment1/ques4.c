#include <stdio.h>

// Function to swap two values
void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate right an array for first p2 elements by 1 position
void ROTATE_RIGHT(int *p1, int p2) {
    for (int i = 0; i < p2; i++) {
        EXCHANGE(&p1[i], &p1[i + 1]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p2 = 3; // Number of elements to be rotated

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ROTATE_RIGHT(arr, p2);

    printf("Rotated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
