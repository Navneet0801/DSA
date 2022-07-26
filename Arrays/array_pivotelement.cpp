#include<bits/stdc++.h>
using namespace std;

int pivotElement(vector<int> arr){
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){
        int mid = (start+end)/2;

        if(arr[mid] < arr[mid-1]){
            return mid;
        }
        else if(arr[mid] < arr[start]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
}

int main(){
    vector<int> arr = {4,5,6,7,8,1,2,3};

    cout<<pivotElement(arr);

    return 0;
}