#include <stdio.h>

void selectionSort(int a[], int n) {
    int i, j, k, t;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        if (k != i) {
            t = a[k];
            a[k] = a[i];
            a[i] = t;
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    
    
    for (i = 0; i < n; i++) {
        printf("Elemnt at the index %d is : ",i);
        scanf("%d", &a[i]);
    }
    
    selectionSort(a, n);
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
