// #include <stdio.h>
// int arr[10]={2,4,6,8,10};
// int n=5;
//  //delete
//  int pos=2;
//  int main(void){
//     for (int i=pos;i<=n-1;i++){
//         arr[i]=arr[i+1];
//     }
//     n--;
//     printf("Array after deletion: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//  }

// #include<stdio.h>
// int arr[10]={1,2,3,4,5,6,7,8,9};
// int n=9;
// int ele=5;
// int main(void){
//     for(int i =0;i<n;i++){
//         if (arr[i]==ele){
//             for (int x = i;x<=n-1;x++){
//                 arr[x]=arr[x+1];
//             }n--; break;
//         }
//     }
//         printf("Array after deletion: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
// }

#include <stdio.h>

int arr[20] = {2, 3, 4, 98, 6, 59, 55, 24};
int total = 8;
int data = 69;

int main(void) {
    for (int i = 0; i < total; i++) {
        if (arr[i] == 6) {
            
            // 1. Shift elements to the right starting from the end of the array
            for (int j = total; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            
            // 2. Insert the new data at the current position
            arr[i] = data;
            
            // 3. Increment the total number of elements
            total++;
            
            // 4. Break out of the loop so we don't insert 69 infinitely
            break; 
        }
    }
    
    // Updated the text to say "insertion" instead of "deletion"
    printf("Array after insertion: ");
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}