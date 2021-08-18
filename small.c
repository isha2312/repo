//2.find Mth smallest number.  

#include <stdio.h>

void merge(int a[], int L, int mid, int R, int b[])
{
   int k=L;
   int i=L;
   int j=mid+1;
   
   while(k<=R)
   {
       if(i>mid)
          b[k++]=a[j++];
          
       else if(j>R)
         b[k++]=a[i++];
         
       else if(a[i]>a[j])
         b[k++]=a[j++];
         
       else
        b[k++]=a[i++];
          
   }
   
   for(k=L;k<=R;k++)
       a[k]=b[k];
}


void merge_sort(int a[], int L, int R, int b[])
{
    if(L==R)
      return;
      
      int mid=(L+R)/2;
      
      merge_sort(a,L,mid,b);
      merge_sort(a,mid+1,R,b);
      merge(a,L,mid,R,b);
}

   

int main()
{
    int num,i,m;
    printf("Enter size: ");
    scanf("%d",&num);
    
    int arr[num],b[num];
    
    printf("Enter array elements: ");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Enter mth smallest element to print: ");
    scanf("%d",&m);
    
    //calling function
    merge_sort(arr,0,num-1,b);
    
    //printing mth smallest element
    printf("%d",arr[m-1]);
    
 return 0;
}
