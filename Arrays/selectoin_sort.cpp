#include<bits/stdc++.h>
using namespace std;

void swaap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
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
    int arr[5] = {10, 40, 50, 20, 30};

    selectionSort(arr, 5);


    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}