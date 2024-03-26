#include <stdio.h>

// Function to find minimum and maximum values in a list
void findMinMax(int arr[], int size) {
    if (size == 0) {
        printf("List is empty\n");
        return;
    }
    
    int min = arr[0]; // Initialize min to the first element
    int max = arr[0]; // Initialize max to the first element
    
    // Traverse the array to find minimum and maximum values
    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    
    // Print the minimum and maximum values
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
}

int main() {
    int arr[] = {5, 3, 9, 2, 7, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    findMinMax(arr, size);
    
    return 0;
}
