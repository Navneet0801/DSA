#include<iostream>
using namespace std;

void swaap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//with recursion
void selectionSort1(int *arr, int start, int end){
    if(start == end-1){
        return;
    }

    int key = start;
    for(int i = start+1; i<end; i++){
        if(arr[i] <  arr[key]){
            key = i;
        }
    }
    swap(arr[key], arr[start]);

    selectionSort1(arr, start+1, end);
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int pos = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[pos]){
                pos = j;
            }
        }
        swaap(arr[i], arr[pos]);
    }
}

int main(){
    int arr[5] = {1,4,5,9,2};

    // selectionSort(arr, 5);
    selectionSort1(arr, 0, 5);


    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}