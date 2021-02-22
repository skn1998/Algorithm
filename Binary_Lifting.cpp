#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll LCA(ll u, ll v, vector<ll> &par, vector<ll> &lev, vector<vector<ll>> &mat, ll maxN)
{
    if(lev[u]<lev[v])
        swap(u, v);
    
    ll k, d = lev[u] - lev[v];
    if(d>0)
    {
        k = (ll)log2(d);
        u = mat[u][k];
        d -= (ll)pow(2, k);   
    }
    
    while(d--)
        u = par[u];
    
    if(u==v)
        return u;
        
    ll i;
    for(i=maxN;i>=0;i-=1)
    {
        if(mat[u][i]!=-1 and mat[u][i]!=mat[v][i])
        {
            u = mat[u][i];
            v = mat[v][i];
        }
    }
    return par[u];
}


void DFS(ll i, vector<bool> &visited, vector<vector<pair<ll, ll>>> &arr, vector<ll> &w, vector<ll> &par, vector<ll> &lev)
{
    ll j;
    for(j=0;j<arr[i].size();j+=1)
    {
        if(visited[arr[i][j].first]==false)
        {
            visited[arr[i][j].first]=true;
            w[arr[i][j].first] = w[i] + arr[i][j].second;
            par[arr[i][j].first] = i;
            lev[arr[i][j].first] = lev[i] + 1;
            DFS(arr[i][j].first, visited, arr, w, par, lev);
        }
    }
}

void solve()
{
    ll n, q, r, i, j, u, v, z, maxN;
    scanf("%lld %lld %lld", &n, &q, &r);
    vector<vector<pair<ll, ll>>> arr(n+1);
    vector<ll> w(n+1);
    vector<ll> par(n+1);
    vector<ll> lev(n+1);
    vector<bool> visited(n+1, false);
    for(i=1;i<n;i+=1)
    {
        scanf("%lld %lld %lld", &u, &v, &z);
        arr[u].push_back(make_pair(v, z));
        arr[v].push_back(make_pair(u, z));
    }
    
    w[r] = 0;
    par[r] = -1;
    lev[r] = 0;
    visited[r] = true;
    DFS(r, visited, arr, w, par, lev);
    
    maxN = (ll)log2(n);
    vector<vector<ll>> mat(n+1, vector<ll>(maxN+1, -1));
    for(i=1;i<=n;i+=1)
        mat[i][0] = par[i];
    
    for(j=1;j<=maxN;j+=1)
    {
        for(i=1;i<=n;i+=1)
        {
            if(mat[i][j-1]!=-1)
            {
                ll p = mat[i][j-1];
                mat[i][j] = mat[p][j-1];
            }
        }
    }
    while(q--)
    {
        scanf("%lld %lld ", &u, &v);
        ll val = w[u] + w[v] - 2*w[LCA(u, v, par, lev, mat, maxN)];
        printf("%lld\n", val);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    scanf("%d", &t);
    while(t--)
        solve();
}
