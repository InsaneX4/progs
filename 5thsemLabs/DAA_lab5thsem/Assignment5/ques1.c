#include <stdio.h>
#include <stdlib.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

// Function to create a min-heap based on age
void heapifyAge(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyAge(arr, n, smallest);
    }
}

// Function to create a max-heap based on weight
void heapifyWeight(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapifyWeight(arr, n, largest);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct person *students = (struct person *)malloc(n * sizeof(struct person));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter student details (Id Name Age Height Weight):\n");
    for (int i = 0; i < n; i++) {
        students[i].name = (char *)malloc(50 * sizeof(char));
        scanf("%d %s %d %d %d", &students[i].id, students[i].name, &students[i].age, &students[i].height, &students[i].weight);
    }

    int option;
    while (1) {
        printf("MAIN MENU (HEAP)\n");
        printf("1. Create a Min-heap based on age\n");
        printf("2. Create a Max-heap based on weight\n");
        printf("3. Display weight of the youngest person\n");
        printf("4. Insert a new person into the Min-heap\n");
        printf("5. Delete the oldest person\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 6) {
            break;
        }

        switch (option) {
            case 1:
                // Create a Min-heap based on age
                for (int i = n / 2 - 1; i >= 0; i--)
                    heapifyAge(students, n, i);
                break;

            case 2:
                // Create a Max-heap based on weight
                for (int i = n / 2 - 1; i >= 0; i--)
                    heapifyWeight(students, n, i);
                break;

            case 3:
                // Display weight of the youngest person
                printf("Weight of youngest student: %.2f kg\n", (float)students[0].weight / 2.20462);
                break;

            case 4:
                // Insert a new person into the Min-heap (based on age)
                n++;
                students = (struct person *)realloc(students, n * sizeof(struct person));
                if (students == NULL) {
                    printf("Memory reallocation failed.\n");
                    return 1;
                }
                printf("Enter new student details (Id Name Age Height Weight): ");
                students[n - 1].name = (char *)malloc(50 * sizeof(char));
                scanf("%d %s %d %d %d", &students[n - 1].id, students[n - 1].name, &students[n - 1].age, &students[n - 1].height, &students[n - 1].weight);
                int idx = n - 1;
                while (idx > 0 && students[idx].age < students[(idx - 1) / 2].age) {
                    swap(&students[idx], &students[(idx - 1) / 2]);
                    idx = (idx - 1) / 2;
                }
                break;

            case 5:
                // Delete the oldest person (root of min-heap based on age)
                if (n <= 0) {
                    printf("No students to delete.\n");
                } else {
                    swap(&students[0], &students[n - 1]);
                    n--;
                    heapifyAge(students, n, 0);
                }
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}
