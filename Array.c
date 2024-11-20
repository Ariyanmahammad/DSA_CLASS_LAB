#include<stdio.h>
int main(){
    int n;
    printf("enter the size of your array: ");
    scanf("%d",&n);
    int arr[n];
    printf("the elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("the elements of the array are: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",arr[i]);
    }
    
    

    return 0;
}