#include<iostream>
using namespace std;

void reverse(int arr[], int size){
    int temp=0;
    for(int i=0;i<size/2;i++)
    {
        temp=arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1]=temp;
    }
}

void display(int arr[], int size){
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[100]={1,2,3,4,5,6,7,8,9,10};
    int size = 10;
    display(arr, size);
    cout<<endl;
    reverse(arr, size);
    display(arr, size);

    return 0;
}