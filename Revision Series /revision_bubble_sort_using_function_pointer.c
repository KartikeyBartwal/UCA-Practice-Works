#include <stdio.h>


void printArr(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        
        printf(" %d ", arr[i]);
    }
    
    printf("\n");
}

// FUNCTION TO COMPARE FOR ASCENDING ORDER

int compareAsc(int a, int b) {
    
    return a > b;  
}

// FUNCTION TO COMPARE FOR DESCENDING ORDER

int compareDesc(int a, int b) {
    
    return a < b;  
}

// FUNCTION TO SWAP TWO ELEMENTS

void swap(int *a, int *b) {
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

// FUNCTION TO SORT ARRAY BASED ON COMPARISON FUNCTION
void sort(int arr[], int n, int (*compare)(int, int)) {
    
    for(int i = 0; i < n - 1; i++) {
        
        for(int j = 0; j < n - i - 1; j++) {  // CORRECT LOOP LIMIT FOR BUBBLE SORT
            
            if(compare(arr[j], arr[j + 1])) {  // COMPARE ADJACENT ELEMENTS
                
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    
    return;
}

// MAIN FUNCTION
int main() {
    
    int arr[] = {5, 2, 9, 1, 5, 10, 1, 3};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Arr: ");
    
    printArr(arr, n);
    
    sort(arr, n, compareAsc);
    
    printf("Ascending order: ");
    printArr(arr, n);
    
    sort(arr, n, compareDesc);
    
    printf("Descending order: ");
    printArr(arr, n);
    
    return 0;
}
