#include <stdio.h>

// FUNCTION TO SORT AN ARRAY USING A COMPARISON FUNCTION
void sort(int arr[], int size, int (*compare)(int, int)) {

    // SIMPLE BUBBLE SORT ALGORITHM FOR DEMONSTRATION
    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - i - 1; j++) {

            // USE THE COMPARISON FUNCTION TO DETERMINE ORDER
            if (compare(arr[j], arr[j + 1]) > 0) {

                // SWAP ELEMENTS IF IN THE WRONG ORDER
                int temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }
        }
    }
}

// COMPARISON FUNCTION FOR ASCENDING ORDER
int compareAsc(int a, int b) {

    return a - b; // RETURN POSITIVE IF A > B, ZERO IF A == B, NEGATIVE IF A < B
}

// COMPARISON FUNCTION FOR DESCENDING ORDER
int compareDesc(int a, int b) {

    return b - a; // RETURN POSITIVE IF B > A, ZERO IF A == B, NEGATIVE IF B < A
}

// FUNCTION TO PRINT THE ARRAY
void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {

        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {5, 2, 9, 1, 5, 6};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    
    printArray(arr, size);

    // SORT IN ASCENDING ORDER
    
    sort(arr, size, compareAsc);
    
    printf("Sorted array (ascending): ");
    
    printArray(arr, size);

    // SORT IN DESCENDING ORDER
    
    sort(arr, size, compareDesc);
    
    printf("Sorted array (descending): ");
    
    printArray(arr, size);

    return 0;
}
