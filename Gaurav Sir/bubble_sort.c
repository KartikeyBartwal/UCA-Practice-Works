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

    // BUBBLE SORT ALGORITHM
    for(int i = 0; i < n - 1; i++) {

        // FLAG TO CHECK IF A SWAP OCCURRED
        int swapped = 0;

        for(int j = 0; j < n - i - 1; j++) {

            // SWAP IF THE ELEMENT FOUND IS GREATER THAN THE NEXT ELEMENT
            if(arr[j] > arr[j + 1]) {

                int temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        // IF NO SWAP OCCURRED, THE ARRAY IS SORTED
        if(swapped == 0) {

            break;
        }
    }

    // PRINT THE SORTED ARRAY
    for(int i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
