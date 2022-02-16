// binarySearch
// we can use stl also such as imp one are:

// binary_search(arr.begin(), arr.end(), search_element))
// returns bool value

// lower_bound(arr1.begin(), arr1.end(), 20)
// returns lower bound.

// upper_bound(arr2.begin(), arr2.end(), 20)- arr2.begin();
//retrun incase of multiple occurences

#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> vec, int low, int high, int x)
{
    while(low<=high)
    {
        int mid=(high+low)/2;
        if(vec[mid]<x)
        {
            low=mid+1;
        }
        else if(vec[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            return mid;
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
    int ans = binarySearch(vec, 0, n-1, x);
    cout<<ans;
}
//test case
// 6          
// 1 2 3 4 5 6
// 5

// 4
