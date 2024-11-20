#include<stdio.h>
int main(){
    int i,j,r,c;
    printf("enter the row number: ");
    scanf("%d",&r);
    printf("enter the column number: ");
    scanf("%d",&c);
    int matrix[r][c],matrix_T[c][r];
    printf("enter the elements of matrix : \n");
    for ( i = 0; i < r; i++)
    {
       for ( j = 0; j < c; j++)
       {
        scanf("%d",&matrix[i][j]);
        
       }
       printf("\n");
       
    }
   
    for ( i = 0; i < r; i++)
    {
       for ( j = 0; j < c; j++)
       {
      matrix_T[j][i]= matrix[i][j];
        
       }
     
       
    }
   
   
    printf("the transpose matrix is : \n");
    for ( i = 0; i < c; i++)
    {
        for(j=0;j<r;j++){
            printf("%d\t",matrix_T[i][j]);
        }
        printf("\n");
    }
    
       return 0; 
}