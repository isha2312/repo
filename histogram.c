// Largest area in a histogram


int min_ele(int *a, int l, int h)
{
    int min=a[l];
    for(int i=l;i<=h;i++)
    {
        // finding the min among everytime
        if(a[i]<=min)
            min=a[i];
    }
    return min;
}

int largestRectangleArea(int* a, int n)
{
    int i,j,min,l,b,ar=0,maxarea=-1; //l=length (min ele within i and j) b=breadth
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            l=min_ele(a,i,j);
            b=j-i+1;
            ar=l*b;
            
            if(ar>maxarea)
            maxarea=ar;
            
            
        }
        
    }
    
    return maxarea;
}
