#include <stdio.h>

// Function to compute binomial coefficient using dynamic programming
unsigned long long binomialCoefficient(int n, int k) {
    unsigned long long dp[n + 1][k + 1];
    int i, j;
    
    // Initialize dp array
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][k];
}

int main() {
    int n = 5, k = 2; // Example values for n and k
    unsigned long long result = binomialCoefficient(n, k);
    
    printf("Binomial Coefficient of %d choose %d is %llu\n", n, k, result);
    return 0;
}
