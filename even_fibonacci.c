//1. Print n numbers in Fibonacci series that are even. 

#include <stdio.h>

void fib(int n)
{
    int a,b,i,c,k=0,j,count=0;
    int arr[20];
    a=0;
    b=1;
    
    i=1;
    
    while(i)
    {
        //putting even values of fibonacci series to an array 
        if(a%2==0)
        {
            count++;
            arr[k]=a;
            k++;
        }
        // if count equals to the count we want then break
        if(count==n)
         break;
        
        c=a+b;
        a=b;
        b=c;
        
        i++;
    }
    
    //printing even elements of series
    for(j=0;j<k;j++)
    {
       printf("%d ",arr[j]);
    }
}


int main()
{
    int num;
    
    //scanning value for n
    printf("Enter the value of num ");
    scanf("%d",&num);
    
    //calling function
    fib(num);

    return 0;
}
