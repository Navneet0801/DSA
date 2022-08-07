#include<iostream>
using namespace std;

bool checkSorted(int arr[], int size){
    //base case
    if(size == 0 || size == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        return checkSorted(arr+1, size-1);
    }
}

int giveSum(int *arr, int size){
    if(size == 0){
        return 0;
    }

    if(size == 1){
        return arr[0];
    }

    int remain = giveSum(arr+1, size-1);
    int sum = arr[0] + remain;

    return sum;
}

int main(){
    int arr[5] = {1,2,3,4,5};

    cout << checkSorted(arr, 5) << endl;

    cout << giveSum(arr, 5);
}