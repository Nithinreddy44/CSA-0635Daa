#include <stdio.h>
#include <limits.h>

#define MAX_KEYS 100

// Function to find optimal binary search tree
float optimalBST(float keys[], float prob[], int n) {
    float cost[n + 1][n + 1];

    // Initialize cost table
    for (int i = 1; i <= n; i++) {
        cost[i][i] = prob[i];
    }

    // Calculate cost for chains of length l
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            cost[i][j] = INT_MAX;
            float sum = 0;
            for (int k = i; k <= j; k++) {
                sum += prob[k];
            }
            for (int k = i; k <= j; k++) {
                float temp = cost[i][k - 1] + cost[k + 1][j] + sum;
                if (temp < cost[i][j]) {
                    cost[i][j] = temp;
                }
                if (k == j) {
                    sum -= prob[k];
                }
            }
        }
    }
    return cost[1][n];
}

int main() {
    int n;
    float keys[MAX_KEYS], prob[MAX_KEYS];

    printf("Enter the number of keys: ");
    scanf("%d", &n);

    printf("Enter the keys and their probabilities:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%f %f", &keys[i], &prob[i]);
    }

    float minCost = optimalBST(keys, prob, n);
    printf("The minimum cost of optimal binary search tree is: %.2f\n", minCost);

    return 0;
}
