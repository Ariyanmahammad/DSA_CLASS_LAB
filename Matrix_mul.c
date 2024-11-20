#include<stdio.h>
int main(){
    int i,j,k,r,c;
    printf("enter the row number: ");
    scanf("%d",&r);
    printf("enter the column number: ");
    scanf("%d",&c);
    int matrix_A[r][c],matrix_B[r][c],matrix_C[r][c];
    printf("enter the elements of matrix_A : \n");
    for ( i = 0; i < r; i++)
    {
       for ( j = 0; j < c; j++)
       {
        scanf("%d",&matrix_A[i][j]);
        
       }
       printf("\n");
       
    }
    printf("enter the elements of matrix_B : \n");
    for ( i = 0; i < r; i++)
    {
       for ( j = 0; j < c; j++)
       {
        scanf("%d",&matrix_B[i][j]);
        
       }
       printf("\n");
       
    }
   
    
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            matrix_C[i][j]=0;
            for ( k = 0; k < c; k++)
            {
                matrix_C[i][j]+=matrix_A[i][k]*matrix_B[k][j];
            }
            
        }
        
    }
    printf("the resultant matrix is : \n");
    for ( i = 0; i < r; i++)
    {
        for(j=0;j<c;j++){
            printf("%d\t",matrix_C[i][j]);
        }
        printf("\n");
    }
    
       return 0; 
}