#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;
    
    // Find proper divisors and sum them up
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0)
            sum += i;
    }
    
    // Check if the sum of divisors equals the number
    if (sum == num)
        return 1; // It's a perfect number
    else
        return 0; // It's not a perfect number
}

int main() {
    int n;

    // Input the number from user
    printf("Enter a number: ");
    scanf("%d", &n);

    // Check if the number is perfect and print the result
    if (isPerfect(n))
        printf("%d is a perfect number.\n", n);
    else
        printf("%d is not a perfect number.\n", n);

    return 0;
}
