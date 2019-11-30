// Bubble Sort //

#include<stdio.h>
int main()
{
    int A[1000], n, i, j, temp, flag;
    scanf("%d", &n);
    for(i=0;i<n;i=i+1)
    {
        scanf("%d", &A[i]);
    }
    for(j=n-1;j>=0;j=j-1)
    {
        flag=0;
        for(i=0;i<=j-1;i=i+1)
        {
            if(A[i]>A[i+1])
            {
                temp=A[i];
                A[i]=A[i+1];
                A[i+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    for(i=0;i<n;i=i+1)
    {
        printf("%d ", A[i]);
    }
}