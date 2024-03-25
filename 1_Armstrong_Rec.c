#include <stdio.h>
int power(int base,int exponent) 
{
    int result=1,i;
    for (i=0;i<exponent;i++) 
    {
        result*=base;
    }
    return result;
}
int countDigits(int num) 
{
    int count=0;
    while (num!=0) 
    {
        count++;
        num/=10;
    }
    return count;
}
int isArmstrong(int num) 
{
    int originalNum=num,numDigits=countDigits(num),armstrongSum=0,digit;
    while (num!=0) 
    {
        digit=num%10;
        armstrongSum+=power(digit,numDigits);
        num/=10;
    }
    return armstrongSum==originalNum;
}
int main() 
{
    int num;
    printf("\nEnter a number = ");
    scanf("%d",&num);
    if (isArmstrong(num))
        printf("\n%d is an Armstrong number\n",num);
    else
        printf("%d is not an Armstrong number\n",num);
}