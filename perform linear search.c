#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int arr[] = {12, 45, 67, 89, 34, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, position;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Call linear search function
    position = linearSearch(arr, n, key);

    if (position != -1) {
        printf("Element found at position %d\n", position + 1);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
