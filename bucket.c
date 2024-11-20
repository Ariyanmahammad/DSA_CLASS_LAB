#include <stdio.h>
#include <stdlib.h>

// Function to sort individual buckets
void bucketSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int bucket[maxVal + 1]; // Create buckets
    for (int i = 0; i <= maxVal; i++) {
        bucket[i] = 0; // Initialize buckets
    }

    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++; // Count occurrences in buckets
    }

    for (int i = 0, j = 0; i <= maxVal; i++) {
        while (bucket[i] > 0) { // Reconstruct sorted array
            arr[j++] = i;
            bucket[i]--;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
