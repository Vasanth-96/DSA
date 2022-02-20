#include<bits/stdc++.h>
using namespace std;
// merge function
void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid-start+1;
    int n2 = end-mid;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++)
    {
        a1[i] = arr[i+start];
    }
    for(int i=0;i<n2;i++)
    {
        a2[i] = arr[i+mid+1];
    }
    int i1 = 0;
    int i2 = 0;
    int index = start;
    while(1)
    {
        if(i1==n1 || i2==n2)
        {
            break;
        }
        if(a1[i1] < a2[i2])
        {
            arr[index] = a1[i1];
            index++;
            i1++;
        }
        else
        {
            arr[index] = a2[i2];
            index++;
            i2++;
        }
    }
    if(i1==n1)
    {
        while(i2<n2)
        {
            arr[index] = a2[i2];
            index++;
            i2++;
        }
    }
    else if(i2==n2)
    {
        while(i1<n1)
        {
            arr[index] = a1[i1];
            index++;
            i1++;
        }
    }
    
}
// merge_sort function
void merge_sort(int arr[], int start, int end)
{
    if(start >= end)
    return;
    
    int mid =(start+end)/2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}
// main function 
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr, 0, n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}