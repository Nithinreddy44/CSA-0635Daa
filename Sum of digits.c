#include <stdio.h>

int main() {
    int num, digit, sum = 0;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate the sum of digits
    while (num != 0) {
        digit = num % 10; // Extract the last digit
        sum += digit;     // Add the last digit to sum
        num /= 10;        // Remove the last digit
    }

    // Display the sum
    printf("Sum of digits: %d\n", sum);

    return 0;
}
