// Cocktail Sort //

#include<iostream>
#include<vector>
using namespace std;
  
int main()
{
    int i, j, temp, N, len, start;
    vector<int> data = {5, 2, 200, 3, 1, 7, 1, 7, 1, 9, 5, 90};
    N = data.size();
    len = N-1;
    start = 0;
    do
    {
        for(i=start;i<=len-1;i+=1)
        {
            if(data[i]>data[i+1])
            {
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
            }
        }
        len-=1;
        for(i=len;i>=start;i-=1)
        {
            if(data[i]<data[i-1])
            {
                temp = data[i];
                data[i] = data[i-1];
                data[i-1] = temp;
            }
        }
        start+=1;
    }
    while(start<len-1);
    for(i=0;i<N;i+=1)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
    data.clear();
  }