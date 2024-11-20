#include <stdio.h>

void countingSort(int arr[], int n) {
    // Find the maximum value in the array
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Create and initialize the frequency array
    int freq[maxVal + 1];
    for (int i = 0; i <= maxVal; i++) {
        freq[i] = 0;
    }

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Reconstruct the sorted array
    for (int i = 0, j = 0; i <= maxVal; i++) {
        while (freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
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

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
