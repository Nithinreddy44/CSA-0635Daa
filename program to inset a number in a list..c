#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int list[], int *size, int position, int element) {
    if (*size >= MAX_SIZE || position < 0 || position > *size) {
        printf("Invalid position or list is full.\n");
        return;
    }

    for (int i = *size - 1; i >= position; i--)
        list[i + 1] = list[i];

    list[position] = element;
    (*size)++;
}

int main() {
    int list[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5;
    int position, element;

    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &position);
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);

    insertElement(list, &size, position, element);

    printf("List after insertion: ");
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
