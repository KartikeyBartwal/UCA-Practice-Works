#include <stdio.h>

#define MAX_SIZE 100

// FUNCTION TO MERGE TWO SUBARRAYS OF arr[]
void merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;

    int n2 = right - mid;

    int L[MAX_SIZE], R[MAX_SIZE];

    // COPY DATA TO TEMP ARRAYS L[] AND R[]
    for(int i = 0; i < n1; i++) {

        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++) {

        R[j] = arr[mid + 1 + j];
    }

    int i = 0;

    int j = 0;

    int k = left;

    // MERGE THE TEMP ARRAYS BACK INTO arr[left..right]
    while(i < n1 && j < n2) {

        if(L[i] <= R[j]) {

            arr[k] = L[i];

            i++;
        } else {

            arr[k] = R[j];

            j++;
        }

        k++;
    }

    // COPY THE REMAINING ELEMENTS OF L[], IF ANY
    while(i < n1) {

        arr[k] = L[i];

        i++;

        k++;
    }

    // COPY THE REMAINING ELEMENTS OF R[], IF ANY
    while(j < n2) {

        arr[k] = R[j];

        j++;

        k++;
    }
}

// FUNCTION TO IMPLEMENT MERGE SORT
void mergeSort(int arr[], int left, int right) {

    if(left < right) {

        // FIND THE MIDDLE POINT
        int mid = left + (right - left) / 2;

        // SORT FIRST AND SECOND HALVES
        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        // MERGE THE SORTED HALVES
        merge(arr, left, mid, right);
    }
}

int main() {

    int n;

    // INPUT THE SIZE OF THE ARRAY
    scanf("%d", &n);

    int arr[MAX_SIZE];

    // INPUT THE ELEMENTS OF THE ARRAY
    for(int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);
    }

    // CALL MERGE SORT
    mergeSort(arr, 0, n - 1);

    // PRINT THE SORTED ARRAY
    for(int i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
