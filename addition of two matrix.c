#include <stdio.h>

// Function to add two matrices
void addMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtractMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Function to perform Strassen's Matrix Multiplication
void strassenMultiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Divide matrices A and B into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate P1 to P7
    subtractMatrix(newSize, B12, B22, temp1); // B12 - B22
    strassenMultiply(newSize, A11, temp1, P1); // A11 * (B12 - B22)

    addMatrix(newSize, A11, A12, temp1); // A11 + A12
    strassenMultiply(newSize, temp1, B22, P2); // (A11 + A12) * B22

    addMatrix(newSize, A21, A22, temp1); // A21 + A22
    strassenMultiply(newSize, temp1, B11, P3); // (A21 + A22) * B11

    subtractMatrix(newSize, B21, B11, temp1); // B21 - B11
    strassenMultiply(newSize, A22, temp1, P4); // A22 * (B21 - B11)

    addMatrix(newSize, A11, A22, temp1); // A11 + A22
    addMatrix(newSize, B11, B22, temp2); // B11 + B22
    strassenMultiply(newSize, temp1, temp2, P5); // (A11 + A22) * (B11 + B22)

    subtractMatrix(newSize, A12, A22, temp1); // A12 - A22
    addMatrix(newSize, B21, B22, temp2); // B21 + B22
    strassenMultiply(newSize, temp1, temp2, P6); // (A12 - A22) * (B21 + B22)

    subtractMatrix(newSize, A11, A21, temp1); // A11 - A21
    addMatrix(newSize, B11, B12, temp2); // B11 + B12
    strassenMultiply(newSize, temp1, temp2, P7); // (A11 - A21) * (B11 + B12)

    // Calculate C11, C12, C21, C22
    addMatrix(newSize, P5, P4, temp1); // P5 + P4
    subtractMatrix(newSize, temp1, P2, temp2); // (P5 + P4) - P2
    addMatrix(newSize, temp2, P6, C11); // (P5 + P4 - P2) + P6

    addMatrix(newSize, P1, P2, C12); // P1 + P2
    addMatrix(newSize, P3, P4, C21); // P3 + P4

    addMatrix(newSize, P5, P1, temp1); // P5 + P1
    subtractMatrix(newSize, temp1, P3, temp2); // (P5 + P1) - P3
    subtractMatrix(newSize, temp2, P7, C22); // (P5 + P1 - P3) - P7

    // Combine submatrices into result matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 2; // Size of matrices (Assuming matrices are square)

    int A[n][n] = {{1, 2}, {3, 4}};
    int B[n][n] = {{5, 6}, {7, 8}};
    int C[n][n]; // Result matrix

    printf("Matrix A:\n");
    printMatrix(n, A);

    printf("\nMatrix B:\n
