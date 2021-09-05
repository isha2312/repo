// 6. Sliding Window

#include<stdio.h>
int sliding_window(int arr[], int n, int k)
{
    int j, max,i,t,b[10];
 
    for (i=0;i <= n-k; i++) 
    {
        max = arr[i];
        for (j = 1; j<k; j++) 
        {
            if (arr[i + j] > max)
            {
                max = arr[i + j];
            }
        }
        printf("%d ", max);
        
    }
    
}




int main()
{
    int n;
    printf("Enter size ");
    scanf("%d",&n);
    
    int a[n],k,i;
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    
    printf("Enter size of sliding window ");
    scanf("%d",&k);
    
    sliding_window(a,n,k);

    return 0;
}





// leetcode solution
// 49/61 test cases passed (time limit exceeded)

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
  int j,i,t,s=0,max;
    
    
    int *arr= (int*)malloc(numsSize*sizeof(int));
 
    for (i=0;i <= numsSize-k; i++) 
    {
        max = nums[i];
        for (j = 1; j<k; j++) 
        {
            if (nums[i + j] > max)
            {
                max = nums[i + j];
                
            }
        }
       
       arr[s]=max;
        s++;
    }
    *returnSize=s;
    return arr;
   
}
