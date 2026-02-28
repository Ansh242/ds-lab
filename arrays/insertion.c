#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50}; 
    int n = 5; 
    int capacity = 100;
    
    int x = 25;
    int pos = 2;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (n >= capacity) {
        printf("Error: Array is full. Cannot insert.\n");
        return 1;
    }

    if (pos < 0 || pos > n) { 
        printf("Error: Invalid position.\n");
        return 1;
    }

    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i]; 
    }

    arr[pos] = x; 
    n++;

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}