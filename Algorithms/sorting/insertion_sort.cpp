// #insertion sort 
// its not best but its its better than selection and bubble
#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int value = arr[i];
        int hole = i;
        while(hole >0 && arr[hole -1]> value)
        {
            arr[hole] = arr[hole-1];
            hole = hole - 1;
        }
        arr[hole] = value;
    }
}
int main()
{
    int n = 10;
    int arr[n] = {1,3,2,4,5,7,6,8,9,10};
    insertion_sort(arr, n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}