#include <stdio.h>

// Function to copy one string to another using recursion
void stringCopy(char *source, char *destination) {
    // Base case: if end of string is reached
    if (*source == '\0') {
        *destination = '\0'; // Terminate destination string
        return;
    }

    // Copy current character and move to next character
    *destination = *source;
    stringCopy(source + 1, destination + 1);
}

int main() {
    char source[100], destination[100];

    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);

    // Call the function to copy the string
    stringCopy(source, destination);

    // Print the copied string
    printf("Copied string: %s\n", destination);

    return 0;
}
