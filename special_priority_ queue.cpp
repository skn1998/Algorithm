#include<bits/stdc++.h> 
using namespace std;

typedef long long int ll; 

struct ele
{
	ll first, second;
};

struct comp
{
	bool operator()(struct ele e1, struct ele e2)
	{
		if(e1.first != e2.first)
		{
			return (e1.first > e2.first);
		}
		return (e1.second < e2.second);
	}
};

void solve()
{
    ll n, i, a, b;
    /*
    A priority_queue having pair of elements and pairs stored in the form of decreasing first value, 
    in case of match of the first value the one having lower second value will be having higher priority. 
    */
    cin>>n;
    priority_queue<struct ele,vector<struct ele>, comp> pq;
    for(i=0;i<n;i+=1)
    {
        cin>>a>>b;
        pq.push({a, b}); // Inserting the value in the priority_queue
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}