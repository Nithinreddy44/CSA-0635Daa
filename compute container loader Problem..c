#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CONTAINERS 100

typedef struct {
    int length;
    int width;
    int height;
} Item;

typedef struct {
    int length;
    int width;
    int height;
    int volume;
} Container;

Item items[MAX_ITEMS];
Container containers[MAX_CONTAINERS];

int numItems, numContainers;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int computeVolume(int length, int width, int height) {
    return length * width * height;
}

int fit(Item item, Container container) {
    return (item.length <= container.length && item.width <= container.width && item.height <= container.height);
}

int loadItems(int index, int remainingVolume) {
    if (index == numItems)
        return 1;

    for (int i = 0; i < numContainers; i++) {
        if (fit(items[index], containers[i]) && containers[i].volume >= items[index].volume) {
            int newVolume = remainingVolume - items[index].volume;
            containers[i].volume -= items[index].volume;
            if (loadItems(index + 1, newVolume))
                return 1;
            containers[i].volume += items[index].volume;
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the dimensions of each item (length width height):\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d %d %d", &items[i].length, &items[i].width, &items[i].height);
        items[i].volume = computeVolume(items[i].length, items[i].width, items[i].height);
    }

    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);

    printf("Enter the dimensions of each container (length width height):\n");
    for (int i = 0; i < numContainers; i++) {
        scanf("%d %d %d", &containers[i].length, &containers[i].width, &containers[i].height);
        containers[i].volume = computeVolume(containers[i].length, containers[i].width, containers[i].height);
    }

    if (loadItems(0, containers[0].volume))
        printf("Items can be loaded into the containers.\n");
    else
        printf("Items cannot be loaded into the containers.\n");

    return 0;
}
