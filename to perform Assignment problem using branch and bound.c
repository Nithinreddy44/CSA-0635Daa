// Implementation of Assignment Problem using Branch and Bound
// This problem can be solved using Hungarian Algorithm for better efficiency
// but here's a simple example of how Branch and Bound could be implemented

#include <stdio.h>
#include <limits.h>

#define N 5

int costMatrix[N][N] = {
    {9, 11, 14, 16, 12},
    {6, 15, 13, 13, 20},
    {12, 12, 10, 18, 18},
    {16, 14, 8, 15, 11},
    {20, 17, 11, 12, 10}
};

int minCost = INT_MAX;
int minAssignment[N];

void branchAndBound(int costMatrix[N][N], int assigned[N], int row, int totalCost) {
    if (row == N) {
        if (totalCost < minCost) {
            minCost = totalCost;
            for (int i = 0; i < N; i++)
                minAssignment[i] = assigned[i];
        }
        return;
    }

    for (int j = 0; j < N; j++) {
        if (!assigned[j]) {
            assigned[j] = 1;
            branchAndBound(costMatrix, assigned, row + 1, totalCost + costMatrix[row][j]);
            assigned[j] = 0;
        }
    }
}

int main() {
    int assigned[N] = {0};
    branchAndBound(costMatrix, assigned, 0, 0);

    printf("Minimum Cost: %d\n", minCost);
    printf("Assignment: ");
    for (int i = 0; i < N; i++)
        printf("(%d,%d) ", i, minAssignment[i]);
    printf("\n");

    return 0;
}
