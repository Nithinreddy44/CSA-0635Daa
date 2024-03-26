#include <stdio.h>

// Function to calculate and print Pascal's Triangle
void printPascalTriangle(int n) {
    int coef = 1;

    for (int i = 0; i < n; i++) {
        // Print spaces for alignment
        for (int space = 1; space <= n - i; space++)
            printf("  ");

        for (int j = 0; j <= i; j++) {
            // Calculate and print the coefficients
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;

            printf("%4d", coef);
        }
        printf("\n");
    }
}

int main() {
    int rows;

    // Input the number of rows from the user
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    // Call the function to print Pascal's Triangle
    printPascalTriangle(rows);

    return 0;
}
