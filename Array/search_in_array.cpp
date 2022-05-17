#include<iostream>
using namespace std;

void linearsearch(int arr[], int size, int element)
{
    int p=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i] == element)
        {
            cout<<"Element found at "<<i+1<<" position\n"; 
            p=1;
        }
    }
    if(p==0)
    cout<<"Element not found\n";
}

void binarysearch(int arr[], int size, int element)
{
    int first, last, mid;
    first = 0;
    last = size-1;
    int p=0;
    while(first<last)
    {
        mid = (first + last)/2;
        if(arr[mid] == element)
        {
            cout<<"Element found at "<<mid+1<<" position\n"; 
            p=1;
        }

        if(arr[mid]<element)
        first = mid+1;

        else
        last = mid-1;
    }

    if(p==0)
    cout<<"Element not found";   
}

int main()
{
    int a[100] = {1,2,3,4,5,6,7,8,9,10};
    int element = 5;
    int size = 10;
    linearsearch(a, size, element);
    binarysearch(a, size, element);

    return 0;
}