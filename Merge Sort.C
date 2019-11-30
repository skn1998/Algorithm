// Merge Sort //

#include<stdio.h>

void merge(int A[], int L[], int R[], int li, int ri)
{
    int l=0, r=0, k=-1;
    while(l<=li && r<=ri)
    {
        if(L[l]>R[r])
        {
            A[k+1]=R[r];
            k=k+1;
            r=r+1;
        }
        else
        {
            A[k+1]=L[l];
            k=k+1;
            l=l+1;
        }
    }
    while(l<=li)
    {
        A[k+1]=L[l];
        k=k+1;
        l=l+1;
    }
    while(r<=ri)
    {
        A[k+1]=R[r];
        k=k+1;
        r=r+1;
    }
}

void mergesort(int A[], int n)
{
    if(n==1)
    {
        return;
    }
    else
    {
        int mid=(n-1)/2;
        int L[1000], R[1000], l=-1, r=-1, i;
        for(i=0;i<=mid;i=i+1)
        {
            L[l+1]=A[i];
            l=l+1;
        }
        for(i=mid+1;i<n;i=i+1)
        {
            R[r+1]=A[i];
            r=r+1;
        }
        for(i=0;i<=l;i=i+1)
        {
            printf("%d ",L[i]);
        }
        printf("\n");
        for(i=0;i<=r;i=i+1)
        {
            printf("%d ",R[i]);
        }
        printf("\n");
        mergesort(L, mid+1);
        mergesort(R, n-mid-1);
        merge(A, L, R, l, r);
        for(i=0;i<n;i=i+1)
        {
            printf("%d ",A[i]);
        }
        printf("\n");
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
    for(i=0;i<n;i=i+1)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    mergesort(A, n);
}