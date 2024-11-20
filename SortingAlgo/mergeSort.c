#include <stdio.h>
#include <limits.h>  


void merge(int arr[], int p, int q, int r) { //p-starting index , q-middle index , r-ending index
    int n1 = q - p + 1; //no of elem in left array
    int n2 = r - q; //no of elem in right array


    int L[n1 + 1], R[n2 + 1];

    //storing values to left & right sub array
    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }


    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
}


void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;  //middle-index
        mergeSort(arr, p, q);     
        mergeSort(arr, q + 1, r);  //r-ending index , p-starting index, q-middle index
        merge(arr, p, q, r);       
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is: \n");
    printArray(arr, arr_size);

    return 0;
}
