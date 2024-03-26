#include <stdio.h>
#include <string.h>

// Function to print reverse of a string using recursion
void reverseString(char str[], int start, int end) {
    if (start >= end)
        return;
    
    // Swapping characters at start and end indices
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    // Recursively call reverseString() with updated indices
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[] = "Hello, World!";
    int length = strlen(str);
    
    printf("Original String: %s\n", str);
    
    // Calling the reverseString() function
    reverseString(str, 0, length - 1);
    
    printf("Reversed String: %s\n", str);
    
    return 0;
}
