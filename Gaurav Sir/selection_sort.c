#include <stdio.h>

#define MAX_SIZE 100

int main() {

    int n;

    // INPUT THE SIZE OF THE ARRAY
    scanf("%d", &n);

    int arr[MAX_SIZE];

    // INPUT THE ELEMENTS OF THE ARRAY
    for(int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);
    }

    // SELECTION SORT ALGORITHM
    for(int i = 0; i < n - 1; i++) {

        // FIND THE MINIMUM ELEMENT IN UNSORTED ARRAY
        int min_idx = i;

        for(int j = i + 1; j < n; j++) {

            if(arr[j] < arr[min_idx]) {

                min_idx = j;
            }
        }

        // SWAP THE FOUND MINIMUM ELEMENT WITH THE FIRST ELEMENT
        int temp = arr[min_idx];

        arr[min_idx] = arr[i];

        arr[i] = temp;
    }

    // PRINT THE SORTED ARRAY
    for(int i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
