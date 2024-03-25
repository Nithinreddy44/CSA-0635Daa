#include <stdio.h>
int findLargestElement(int arr[],int n) 
{
    int largest=arr[0];
    for (int i=1;i<n;i++) 
    {
        if (arr[i]>largest) 
        {
            largest=arr[i];
        }
    }
    return largest;
}
int main() 
{
    int arr[100],n,i,largest;
    printf("\nEnter the number of elements in the array = ");
    scanf("%d",&n);
    printf("\nEnter %d elements:\n",n);
    for (i=0;i<n;i++) 
    {
        scanf("%d",&arr[i]);
    }
    largest=findLargestElement(arr,n);
    printf("\nThe largest element in the array is = %d\n",largest);
}