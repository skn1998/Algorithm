// Selection Sort //

#include<stdio.h>
int main()
{
    int n, A[10000], i, j, temp, min, pos;
    scanf("%d", &n);
    for(i=0;i<n;i=i+1)
    {
        scanf("%d", &A[i]);
    }
    for(i=0;i<n;i=i+1)
    {
        min=A[i];
        pos=i;
        for(j=i+1;j<n;j=j+1)
        {
            if(A[j]<min)
            {
                min=A[j];
                pos=j;
            }
        }
        temp=A[i];
        A[i]=A[pos];
        A[pos]=temp;
    }
    for(i=0;i<n;i=i+1)
    {
        printf("%d ", A[i]);
    }
}