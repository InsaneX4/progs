#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct person
struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// Function to swap two person structs
void swap(struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heapify function
void minHeapify(struct person *arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;
    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Max-Heapify function
void maxHeapify(struct person *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;
    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Build a min-heap
void buildMinHeap(struct person *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Build a max-heap
void buildMaxHeap(struct person *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Function to read data from file
int readData(struct person **people, int *n)
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("File not found!\n");
        return 0;
    }

    fscanf(file, "%d", n);
    *people = (struct person *)malloc(*n * sizeof(struct person));

    for (int i = 0; i < *n; i++)
    {
        (*people)[i].name = (char *)malloc(50 * sizeof(char));
        fscanf(file, "%d %s %d %d %d",
               &(*people)[i].id,
               (*people)[i].name,
               &(*people)[i].age,
               &(*people)[i].height,
               &(*people)[i].weight);
    }

    fclose(file);
    return 1;
}

// Function to display weight of the youngest person
void displayYoungestWeight(struct person *arr, int n)
{
    if (n == 0)
    {
        printf("No data available.\n");
        return;
    }

    buildMinHeap(arr, n);
    printf("Weight of youngest student: %.2lf kg\n", arr[0].weight * 0.453592);
}

// Function to insert a new person into the min-heap
void insertNewPerson(struct person **arr, int *n)
{
    (*n)++;
    *arr = (struct person *)realloc(*arr, (*n) * sizeof(struct person));

    printf("Enter the new person's id, name, age, height, and weight (in pounds): ");
    scanf("%d %s %d %d %d",
          &(*arr)[*n - 1].id,
          (*arr)[*n - 1].name,
          &(*arr)[*n - 1].age,
          &(*arr)[*n - 1].height,
          &(*arr)[*n - 1].weight);

    buildMinHeap(*arr, *n);
    printf("New person inserted into the min-heap.\n");
}

// Function to delete the oldest person
void deleteOldestPerson(struct person *arr, int *n)
{
    if (*n == 0)
    {
        printf("No data available.\n");
        return;
    }

    buildMaxHeap(arr, *n);
    printf("Deleting oldest person with id: %d\n", arr[0].id);

    // Move the last element to the root and max-heapify
    arr[0] = arr[*n - 1];
    (*n)--;

    buildMaxHeap(arr, *n);
}

// Function to free memory
void freeMemory(struct person *arr, int n)
{
    for (int i = 0; i < n; i++)
        free(arr[i].name);
    free(arr);
}

int main()
{
    struct person *people = NULL;
    int n = 0;
    int option;

    while (1)
    {
        printf("MAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            if (readData(&people, &n))
                printf("Data read successfully.\n");
            break;

        case 2:
            buildMinHeap(people, n);
            printf("Min-heap based on age created.\n");
            break;

        case 3:
            buildMaxHeap(people, n);
            printf("Max-heap based on weight created.\n");
            break;

        case 4:
            displayYoungestWeight(people, n);
            break;

        case 5:
            insertNewPerson(&people, &n);
            break;

        case 6:
            deleteOldestPerson(people, &n);
            break;

        case 7:
            freeMemory(people, n);
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid option! Please enter a valid option.\n");
        }
    }

    return 0;
}
