// #include <stdio.h>
// int a[10]={10,20,30,40,50};
// int total=5;

// int del_index=2;

// int main(){

// for (int i = del_index; i < total - 1; i++) {
//         a[i] = a[i + 1];
//     }
// total--;

// for (int i=0;i<total;i++){
//     printf("%d ",a[i]);
// }

// }

// #include<stdio.h>
// int a[10]={10,20,30,40,50};
// int total=5;

// int pos=3;
// int val=25;

// int main(){
//     for (int i=total-1;i>=pos;i--){
//     a[i+1]=a[i];
//     }
//     a[pos] = val;
//     total++;
//     for (int i = 0; i < total; i++) {
//         printf("%d ", a[i]);
//     }
// }

// #include<stdio.h>
// int arr[10]={1,2,3,4,5,6,7,8,9,10};
// int main(void){
//     int val=2;
//     for(int i=0;i<=9;i++){
//         if (arr[i]==val){
//             printf("found");
//         }
//     }
// }

#include <stdio.h>
int arr[10] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
int main(void) {
    int val = 6;
    int left = 0;
    int right = 9;
    int is_found = 0;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == val) {
            is_found = 1;
            break;
        }
        if (arr[mid] < val) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (is_found == 1) {
        printf("found at index %d\n", mid);
    } else {

        for (int i=right;i>=0;i--){
            if (arr[i]<val){
            printf("%d",i+1);
            break;
        }
    }
    }
    return 0;
}