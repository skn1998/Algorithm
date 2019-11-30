// Count Sort //

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, A[1000], max=-1, i, count[10000], sumcount[10000], result[10000];
    scanf("%d", &n);
    for(i=0;i<n;i=i+1)
    {
        scanf("%d", &A[i]);
        if(A[i]>max)
        {
            max=A[i];
        }
    }
    for(i=0;i<=max;i=i+1)
    {
        count[i]=0;
    }
    for(i=0;i<n;i=i+1)
    {
        count[A[i]]=count[A[i]]+1;
    }
    sumcount[0]=count[0];
    for(i=0;i<=max;i=i+1)
    {
        sumcount[i]=sumcount[i-1]+count[i];
    }
    for(i=0;i<n;i=i+1)
    {
        result[sumcount[A[i]]]=A[i];
        sumcount[A[i]]=sumcount[A[i]]-1;
    }
    for(i=0;i<n;i=i+1)
    {
        printf("%d ", result[i]);
    }
}