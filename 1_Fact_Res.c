#include <stdio.h>
unsigned long long factorial(int n) 
{
    if (n==0||n==1)
        return 1;
    else
        return n*factorial(n-1);
}
int main() 
{
    int num;
    printf("\nEnter a number = ");
    scanf("%d",&num);
    if (num<0) 
    {
        printf("\nGive number greater than 0\n");
    } 
    else 
    {
        unsigned long long fact=factorial(num);
        printf("Factorial of %d is %llu\n",num,fact);
    }
}