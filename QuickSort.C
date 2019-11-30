// QuickSort //

#include<stdio.h>

int partition(int temp[], int l, int r)
{
    int i, pivot=temp[r], pindex=l, flag;
    for(i=l;i<r;i=i+1)
    {
        if(temp[i]<=pivot)
        {
            flag=temp[i];
            temp[i]=temp[pindex];
            temp[pindex]=flag;
            pindex=pindex+1;
        }
    }
    flag=temp[r];
    temp[r]=temp[pindex];
    temp[pindex]=flag;
    return(pindex);
}


void quicksort(int temp[], int l, int r)
{
    int ind;
    if(l>=r)
    {
        return;
    }
    else
    {
        ind=partition(temp, l, r);
        quicksort(temp, l, ind-1);
        quicksort(temp, ind+1, r);
    }
}

int main()
{
    int n, A[1000], i;
    scanf("%d", &n);
    for(i=0;i<n;i=i+1)
    {
        scanf("%d", &A[i]);
    }
    quicksort(A, 0, n-1);
    for(i=0;i<n;i=i+1)
    {
        printf("%d ", A[i]);
    }
}