#include <stdio.h>

// Function to print the pattern recursively
void printPattern(int n, int row, int col) {
    // Base case: If the current column exceeds the row number, print a newline
    if (col > row) {
        printf("\n");
        return;
    }
    
    // Print the current column number
    printf("%d ", col);
    
    // Recursive call to print the next column
    printPattern(n, row, col + 1);
}

// Function to print the pattern for each row
void printPatternRows(int n, int row) {
    // Base case: If all rows are printed, return
    if (row > n) {
        return;
    }
    
    // Print the pattern for the current row
    printPattern(n, row, 1);
    
    // Recursive call to print the next row
    printPatternRows(n, row + 1);
}

int main() {
    int n = 4; // Number of rows

    // Call the function to print the pattern
    printPatternRows(n, 1);

    return 0;
}
