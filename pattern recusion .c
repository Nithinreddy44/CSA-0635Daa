#include <stdio.h>

// Function to print the pattern recursively
void printPattern(int n, int m) {
    // Base case: If all columns are printed, move to the next row
    if (m == n + 1) {
        printf("\n");
        return;
    }
    
    // Print the current column number
    printf("%d ", m);
    
    // Recursive call to print the next column
    printPattern(n, m + 1);
}

// Function to print the pattern for each row
void printPatternRows(int n) {
    // Base case: If all rows are printed, return
    if (n == 0) {
        return;
    }
    
    // Print the pattern for the current row
    printPatternRows(n - 1);
    printPattern(n, 1);
}

int main() {
    int rows;

    // Input the number of rows from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Call the function to print the pattern
    printPatternRows(rows);

    return 0;
}
