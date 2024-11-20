#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int p, int r) {//p-starting idx,r-ending idx
    int x = a[r]; //pivot element
    int i = p - 1;

    for (int j = p; j < r ; j++) {
        if (a[j] <= x) {
            i++;
            swap(&a[i], &a[j]);  
        }
    }
    swap(&a[i + 1], &a[r]);  
    return i + 1;
}

void quickSort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);  
        quickSort(a, p, q - 1);      
        quickSort(a, q + 1, r);     
    }
}


void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {12, 4, 13, 9, 5, 6, 10};
    int size = sizeof(a) / sizeof(a[0]);

    printf("Unsorted array: ");
    printArray(a, size);

    quickSort(a, 0, size - 1);

    printf("Sorted array: ");
    printArray(a, size);

    return 0;
}
