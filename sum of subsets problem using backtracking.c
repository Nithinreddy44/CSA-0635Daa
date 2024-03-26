#include <stdio.h>

#define MAX_SIZE 100

int subset[MAX_SIZE]; // Array to store the subset
int n; // Number of elements in the set

// Function to find subsets that sum up to target recursively
void findSubsets(int set[], int target, int sum, int k, int idx) {
    if (sum == target) {
        printf("Subset found: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }
    if (idx == n || sum > target) {
        return;
    }
    // Include the current element in the subset
    subset[k] = set[idx];
    findSubsets(set, target, sum + set[idx], k + 1, idx + 1);
    // Exclude the current element from the subset
    findSubsets(set, target, sum, k, idx + 1);
}

int main() {
    int set[MAX_SIZE], target;

    // Input number of elements in the set
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input elements of the set
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    // Input target sum
    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum equal to %d:\n", target);
    findSubsets(set, target, 0, 0, 0);

    return 0;
}
