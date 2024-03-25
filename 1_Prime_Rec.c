#include <stdio.h>
int isPrimeHelper(int num,int divisor) 
{
    if (divisor==1)
        return 1;
    else 
    {
        if (num%divisor==0)
        {
            return 0;
        }
        else
        {
            return isPrimeHelper(num,divisor-1);
        }
    }
}
int isPrime(int num) 
{
    if (num<=1)
    {
        return 0;
    }
    else
    {
        return isPrimeHelper(num,num/2);
    }
}
int main() 
{
    int num;
    printf("\nEnter a number = ");
    scanf("%d",&num);
    if (isPrime(num))
        printf("\n%d is a prime number\n", num);
    else
        printf("%d is not a prime number.\n", num);
}