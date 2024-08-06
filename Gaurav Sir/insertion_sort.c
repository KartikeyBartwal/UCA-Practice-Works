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

    // INSERTION SORT ALGORITHM
    for(int i = 1; i < n; i++) {

        int key = arr[i];

        int j = i - 1;

        // MOVE ELEMENTS OF arr[0..i-1], THAT ARE GREATER THAN KEY, TO ONE POSITION AHEAD OF THEIR CURRENT POSITION
        while(j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];

            j = j - 1;
        }

        arr[j + 1] = key;
    }

    // PRINT THE SORTED ARRAY
    for(int i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
