#include <stdio.h>
#define N 100
void multiplyMatrix(int mat1[N][N],int mat2[N][N],int res[N][N],int size) 
{
    int i,j,k;
    for (i=0;i<size;i++) 
    {
        for (j=0;j<size;j++) 
        {
            res[i][j]=0;
            for (k=0;k<size;k++) 
            {
                res[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
}
int main() 
{
    int mat1[N][N],mat2[N][N],res[N][N],size,i,j;
    printf("\nEnter the size of the matrices = ");
    scanf("%d",&size);
    for (i=0;i<size;i++) 
    {
        for (j=0;j<size;j++) 
        {
            mat1[i][j]=i+j;
            mat2[i][j]=i-j;
        }
    }
    multiplyMatrix(mat1,mat2,res,size);
    return 0;
}