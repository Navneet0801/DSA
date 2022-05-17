#include<iostream>
using namespace std;

// code for traversal
void displayarray(int a[], int size)
{
    for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
}

//code for insertion
int indinsertion(int arr[],int size, int capacity, int element, int index)
{
    for(int i=size-1; i>=index-1; i--)
    arr[i+1] = arr[i];

    arr[index-1] = element;
    return 1;
}

//code for deletion
int inddeletion(int arr[], int size, int index_del)
{
    for(int i=index_del; i<size; i++)
    arr[i] = arr[i+1];

    return 1;
}

int main()
{
    int arr[100] = {1, 2, 3, 4, 5, 6};
    int size = 6; int index = 3;
    displayarray(arr, size);
    int element = 45;
    indinsertion(arr, size, 100, element, index);
    size+=1;
    cout<<endl;
    displayarray(arr, size);
    int index_del = 4;
    inddeletion(arr, size, index_del);
    size-= 1;
    cout<<endl;
    displayarray(arr, size);    

    return 0;
}