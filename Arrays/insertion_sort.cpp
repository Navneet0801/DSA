#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 and arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[5] = {100, 40, 50, 20, 30};

    insertionSort(arr, 5);


    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}