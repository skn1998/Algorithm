// Insertion Sort //

#include<stdio.h>
int main()
{
    int n, A[1000], i, j, temp, pos;
    scanf("%d", &n);
    for(i=0;i<n;i=i+1)
    {
        scanf("%d", &A[i]);
    }
    for(i=0;i<n;i=i+1)
    {
        pos=i;
        for(j=i-1;j>=0;j=j-1)
        {
            if(A[j]>A[pos])
            {
                temp=A[pos];
                A[pos]=A[j];
                A[j]=temp;
                pos=j;
            }
            else
            {
                break;
            }
        }
    }
    for(i=0;i<n;i=i+1)
    {
        printf("%d ", A[i]);
    }
}