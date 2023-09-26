#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Include limits.h for INT_MAX

// Define the struct person
struct person
{
    int id;
    char name[50]; // Assuming a maximum name length of 50 characters
    int age;
    int height;
    int weight;
};

// Function to heapify a subtree rooted with node i
// n is the size of the heap
void minHeapify(struct person *persons, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare the left child with the current smallest node
    if (left < n && persons[left].age < persons[smallest].age)
        smallest = left;

    // Compare the right child with the current smallest node
    if (right < n && persons[right].age < persons[smallest].age)
        smallest = right;

    // If the smallest node is not the current node, swap them
    if (smallest != i)
    {
        struct person temp = persons[i];
        persons[i] = persons[smallest];
        persons[smallest] = temp;

        // Recursively heapify the affected subtree
        minHeapify(persons, n, smallest);
    }
}

// Function to create a min-heap based on age
void createMinHeap(struct person *persons, int n)
{
    // Build a min-heap from the input data
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(persons, n, i);
    }
}

// Function to display the weight of the youngest person
// Function to display the weight of the youngest person in kilograms
void displayYoungestWeight(struct person *persons, int n)
{
    if (n <= 0)
    {
        printf("No persons in the array.\n");
        return;
    }

    int youngestAge = INT_MAX; // Initialize with a very high age
    int youngestWeight = -1;   // Initialize with a negative weight (assuming weight can't be negative)

    // Iterate through the array to find the youngest person
    for (int i = 0; i < n; i++)
    {
        if (persons[i].age < youngestAge)
        {
            youngestAge = persons[i].age;
            youngestWeight = persons[i].weight;
        }
    }

    if (youngestWeight != -1)
    {
        // Convert the weight from pounds to kilograms
        double weightInKg = youngestWeight * 0.453592;

        printf("Weight of the youngest person (age %d) is: %.2f kg\n", youngestAge, weightInKg);
    }
    else
    {
        printf("No youngest person found.\n");
    }
}

// Function to insert a new person into the min-heap
void insertIntoMinHeap(struct person *persons, int *n)
{
    if (*n == 0)
    {
        printf("The heap is empty. Cannot insert.\n");
        return;
    }

    // Increase the size of the heap by 1
    (*n)++;

    // Get the index of the new element
    int index = *n - 1;

    // Prompt the user for the details of the new person
    printf("Enter the ID, Name, Age, Height, and Weight of the new person: ");
    scanf("%d %s %d %d %d", &persons[index].id, persons[index].name, &persons[index].age, &persons[index].height, &persons[index].weight);

    // Perform heapify-up to maintain the min-heap property
    while (index > 0 && persons[(index - 1) / 2].age > persons[index].age)
    {
        // Swap the new element with its parent
        struct person temp = persons[index];
        persons[index] = persons[(index - 1) / 2];
        persons[(index - 1) / 2] = temp;

        // Move up to the parent index
        index = (index - 1) / 2;
    }

    printf("New person inserted into the min-heap.\n");
}

// Function to delete the oldest person from the min-heap
void deleteOldestPerson(struct person *persons, int *n)
{
    if (*n == 0)
    {
        printf("The heap is empty. Cannot delete.\n");
        return;
    }

    // The oldest person is at the root of the min-heap (index 0)
    // To delete them, we will replace the root with the last element in the heap
    // Then, we perform a heapify-down operation to restore the min-heap property

    // Swap the root with the last element
    struct person temp = persons[0];
    persons[0] = persons[*n - 1];
    persons[*n - 1] = temp;

    // Decrease the size of the heap
    (*n)--;

    // Perform heapify-down to maintain the min-heap property
    int index = 0;
    int smallest;

    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        smallest = index;

        if (left < *n && persons[left].age < persons[smallest].age)
            smallest = left;

        if (right < *n && persons[right].age < persons[smallest].age)
            smallest = right;

        if (smallest != index)
        {
            // Swap with the smaller child
            struct person temp = persons[index];
            persons[index] = persons[smallest];
            persons[smallest] = temp;

            index = smallest;
        }
        else
        {
            // No more swapping needed
            break;
        }
    }

    printf("Oldest person has been deleted from the min-heap.\n");
}

int main()
{
    int option, n = 0;
    struct person *persons = NULL;

    do
    {
        // Display the menu and get the user's choice
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on age\n");
        printf("3. Display weight of the youngest person\n");
        printf("4. Insert a new person into the Min-heap\n");
        printf("5. Delete the oldest person\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                // Read data from file (you can implement this function)
                printf("Enter the number of persons: ");
                scanf("%d", &n);
                persons = (struct person *)malloc(n * sizeof(struct person));
                printf("Enter the data in the format: ID Name Age Height Weight\n");
                for (int i = 0; i < n; i++)
                {
                    scanf("%d %s %d %d %d", &persons[i].id, persons[i].name, &persons[i].age, &persons[i].height, &persons[i].weight);
                }
                break;
            case 2:
                if (n == 0)
                {
                    printf("No data to create a heap. Please read data first.\n");
                }
                else
                {
                    if (persons != NULL)
                        free(persons);

                    persons = (struct person *)malloc(n * sizeof(struct person));

                    if (persons == NULL)
                    {
                        printf("Memory allocation failed.\n");
                        return 1;
                    }
                    createMinHeap(persons, n);
                    printf("Min-heap based on age has been created.\n");
                }
                break;
            case 3:
                displayYoungestWeight(persons, n);
                break;
            case 4:
                insertIntoMinHeap(persons, &n);
                break;
            case 5:
                deleteOldestPerson(persons, &n);
                break;
            case 6:
                if (persons != NULL)
                    free(persons);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 6);

    return 0;
}
