#include<stdio.h>
#include<stdlib.h>
int sum(int a , int b){
    return (a+b);
}
int main(){
    int a , b;
    printf("enter the 1st number: ");
    scanf("%d",&a);
    printf("enter the second nuber: ");
    scanf(" %d",&b);

    printf(" %d + %d = %d",a,b,sum(a,b));
    

    return 0;
}

