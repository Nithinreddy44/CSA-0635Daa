#include <stdio.h>
int fibonacci(int n)
{
    if (n<=1)
        return n;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
void printFibonacci(int n) 
{
    int i;
    for (i=0;i<n;i++) 
    {
        printf("%d ",fibonacci(i));
    }
}
int main() 
{
    int n;
    printf("\nEnter the number of terms = ");
    scanf("%d",&n);
    printf("\nFibonacci Series up to %d terms:\n", n);
    printFibonacci(n);
}