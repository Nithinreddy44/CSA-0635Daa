#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

    // Initialize the dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is stored at dp[n][capacity]
    return dp[n][capacity];
}

int main() {
    int weights[MAX_ITEMS], values[MAX_ITEMS];
    int n, capacity;

    // Input number of items and capacity of the knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Input weights and values of items
    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter the values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Calculate and print the maximum value
    int max_value = knapsack(weights, values, n, capacity);
    printf("Maximum value that can be obtained: %d\n", max_value);

    return 0;
}
