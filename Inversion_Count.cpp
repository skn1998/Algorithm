#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll count;

void Merge(ll l, ll m, ll r, vector<ll> &arr)
{
    ll l_size = m-l+1, r_size = r-m, i, j;
    vector<ll> left, right;
    for(i=l;i<=m;i+=1)
        left.push_back(arr[i]);
        
    for(i=m+1;i<=r;i+=1)
        right.push_back(arr[i]);
        
    i = 0;
    j = 0;
    while(i<l_size and j<r_size)
    {
        if(left[i]>right[j])
        {
            arr[l] = right[j];
            ::count+=(l_size-i);
            j+=1;
        }
        else
        {
            arr[l] = left[i];
            i+=1;
        }
        l+=1;
    }
    while(i<l_size)
    {
        arr[l] = left[i];
        i+=1;
        l+=1;
    }
    while(j<r_size)
    {
        arr[l] = right[j];
        j+=1;
        l+=1;
    }
}

void MergeSort(ll l, ll r, vector<ll> &arr)
{
    if(l==r)
        return;
        
    ll m = (l+r)/2;
    MergeSort(l, m, arr);
    MergeSort(m+1, r, arr);
    Merge(l, m, r, arr);
}

void solve()
{
    ll i, n;
    ::count = 0;
    cin>>n;
    vector<ll> arr(n);
    for(i=0;i<n;i+=1)
        cin>>arr[i];
    
    MergeSort(0, n-1, arr);
    cout<<::count<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
