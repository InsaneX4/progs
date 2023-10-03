#include <stdio.h>
#include <stdlib.h>

struct Item {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};


void heapify(struct Item arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio < arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio < arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        struct Item temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(struct Item arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        struct Item temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void fractional_knapsack(struct Item items[], int num_items, float capacity) {
    heap_sort(items, num_items);
    float result[num_items];
    float max_profit = 0;

    for (int i = 0; i < num_items; i++) {
        if (items[i].item_weight <= capacity) {
            result[items[i].item_id - 1] = 1.0;
            max_profit += items[i].item_profit;
            capacity -= items[i].item_weight;
        } else {
            result[items[i].item_id - 1] = capacity / items[i].item_weight;
            max_profit += items[i].profit_weight_ratio * capacity;
            break;
        }
    }

    printf("Output:\n");
    printf("Item No\tProfit\tWeight\tAmount to be taken\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%.6lf\t%.6lf\t%.6lf\n", items[i].item_id, items[i].item_profit, items[i].item_weight, result[i]);
    }

    printf("Maximum profit: %.6lf\n", max_profit);
}

int main() {
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    struct Item items[num_items];

    for (int i = 0; i < num_items; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    float capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    fractional_knapsack(items, num_items, capacity);

    return 0;
}



