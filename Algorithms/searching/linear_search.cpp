// linearSearch


#include<bits/stdc++.h>
using namespace std;
int linearSearch(vector<int> vec, int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if(vec[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    int x;
    cin>>x;
    int ans = linearSearch(vec, n, x);
    cout<<ans;
}
//test case
// 6          
// 1 2 3 4 5 6
// 5

// 4
