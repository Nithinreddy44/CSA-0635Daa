#include <stdio.h>

// Function to reverse a number recursively
int reverse(int num, int rev) {
    // Base case: when num becomes 0, return the reversed number
    if (num == 0)
        return rev;
    
    // Extract the last digit from num
    int digit = num % 10;
    // Update rev by adding the last digit
    rev = rev * 10 + digit;
    
    // Recursively call reverse with the remaining part of the number
    return reverse(num / 10, rev);
}

int main() {
    int num, reversedNum;
    
    // Input the number from user
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Call the reverse function
    reversedNum = reverse(num, 0);
    
    // Output the reversed number
    printf("Reverse of %d is %d\n", num, reversedNum);
    
    return 0;
}
