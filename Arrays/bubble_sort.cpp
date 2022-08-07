#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//with recursion
void bubbleSort1(int arr[], int n){
    if(n == 1 || n == 0){
        return;
    }

    int j = 0;
    while(j < n-1){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
        j++;
    }
    bubbleSort1(arr, n-1);
}


//without recursion
void bubbleSort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[8] = {45,23,1,26,58,79,45,12};

    // bubbleSort(arr, 5);
    bubbleSort1(arr, 8);


    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}