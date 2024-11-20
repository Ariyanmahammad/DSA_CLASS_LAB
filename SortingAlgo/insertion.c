// #include <stdio.h>
// #define MAX_SIZE 100 

// void insertionSort(int a[], int n) {
//     int i, j, key;
//     for (j = 1; j < n; j++) {
//         key = a[j];
//         i = j - 1;
//         while (i >= 0 && a[i] > key) {
//             a[i + 1] = a[i];
//             i--;;
//         }
//         a[i + 1] = key;
//     }
// }

// int main() {
//     int n, i;
//     printf("Enter number of elements (<= 100): ");
//     scanf("%d", &n);
    

//     int a[MAX_SIZE];
    

//     for (i = 0; i < n; i++) {
//         printf("Elemnt at the position %d is : ",i);
//         scanf("%d", &a[i]);
//     }
    
//     insertionSort(a, n);
    
//     printf("Sorted array: ");
//     for (i = 0; i < n; i++) {
//         printf("%d ", a[i]);
//     }
    
//     return 0;
// }
    #include <stdio.h>

    void swap(int *a ,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    }

    void insert(int arr[],int size){
    
    for(int i=1;i<=size;i++ ){
        if(arr[i-1]>arr[i]){
        swap(&arr[i-1],&arr[i]);
        
        insert(arr,size);
        }
    }
    
    
    }

    void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
    }



    int main(){
    
    int arr[]={2,5,4,47,8,645,87,9,45,687,9,44,48,97,64,87,54,68,79,65,4,7,6,11,3};
    
    int size=sizeof(arr)/sizeof(arr[0]);
    
    printarray(arr,size);
    
    insert(arr,size-1);
    
    
    printarray(arr,size);
    
    return 0;
    }