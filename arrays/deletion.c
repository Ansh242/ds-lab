#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 25, 30, 40, 50}; 
    int n = 6; 
    
    int pos = 2;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (pos < 0 || pos >= n) {
        printf("Error: Invalid position to delete.\n");
        return 1;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1]; 
    }

    n--;

    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}