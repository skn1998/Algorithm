// Heap Sort //

#include<stdio.h>
int main()
{
    int n, A[10000], i, pos, temp, loc, max, result[10000], k, j;
    scanf("%d", &n);
    for(i=0;i<n;i=i+1)
    {
        scanf("%d", &A[i]);
    }
    for(i=n/2 ;i>=0; i=i-1)
    {
        pos=i;
        while(pos<=n-1)
        {
            if(2*pos+2<=n-1)
            {
                if(A[2*pos+1]>A[2*pos+2])
                {
                    max=A[2*pos+1];
                    loc=2*pos+1;
                }
                else
                {
                    max=A[2*pos+2];
                    loc=2*pos+2;
                }
                if(max>A[pos])
                {
                    temp=A[pos];
                    A[pos]=A[loc];
                    A[loc]=temp;
                    pos=loc;
                }
                else
                {
                    break;
                }
            } 
            else if(2*pos+1==n-1)
            {
                if(A[pos]<A[2*pos+1])
                {
                    temp=A[pos];
                    A[pos]=A[2*pos+1];
                    A[2*pos+1]=temp;
                    pos=2*pos+1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    
    
    k=n-1;
    while(k>=0)
    {
        result[k]=A[0];
        A[0]=A[k];
        k=k-1;
        pos=0;
        while(pos<=k)
        {
            if(2*pos+2<=k)
            {
                if(A[2*pos+1]>A[2*pos+2])
                {
                    max=A[2*pos+1];
                    loc=2*pos+1;
                }
                else
                {
                    max=A[2*pos+2];
                    loc=2*pos+2;
                }
                if(max>A[pos])
                {
                    temp=A[pos];
                    A[pos]=A[loc];
                    A[loc]=temp;
                    pos=loc;
                }
                else
                {
                    break;
                }
            }
            else if(2*pos+1==k)
            {
                if(A[pos]<A[2*pos+1])
                {
                    temp=A[pos];
                    A[pos]=A[2*pos+1];
                    A[2*pos+1]=temp;
                    pos=2*pos+1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    for(i=0;i<n;i=i+1)
    {
        printf("%d ", result[i]);
    }
}