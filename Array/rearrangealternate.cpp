#include<iostream>
using namespace std;

void display(int arr[], int size){
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void arrange(int arr[], int size){
    
}

int main()
{
    int arr[100] = {1,2,3,4,5,6,7,8,9,10};
    int size = 10;
    display(arr, size);
    cout<<endl;
    arrange(arr, size);
    display(arr, size);

    return 0;
}