// bubble sort
// selection sort generally swap by checking the next element ni each iterations
// arrays are also passed as reference.
#include<bits/stdc++.h>
using namespace std;
void bubblesort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)//since the i comparisions are one already in each iterations
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main()
{
    int n=10;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubblesort(arr, n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}