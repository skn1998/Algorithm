// Binary Search //

#include<stdio.h>
int main()
{
    int A[12]={-2, -1, 0, 4, 6, 8, 9, 10, 45, 78, 89, 100},T,t;
    scanf("%d",&T);
    for(t=0;t<T;t=t+1)
    {
        int mid,i,n=12,left,right,k;
        scanf("%d",&k);
        left=0;
        right=n-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(A[mid]==k)
            {
                printf("%d found at index %d.\n",k,mid);
                break;
            }
            else if(A[mid]<k)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        if(left>right)
        {
            printf("%d not found.\n",k);
        }
    }
    return(0);
}