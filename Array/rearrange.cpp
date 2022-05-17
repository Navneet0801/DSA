#include<iostream>
using namespace std;

void display(int arr[], int size){
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void fixarray(int arr[], int size){
    int temp=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(arr[j]==i)
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}

int main()
{
    int arr[100] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int size = 10;
    display(arr, size);
    cout<<endl;
    fixarray(arr, size);
    display(arr, size);

    return 0;
}