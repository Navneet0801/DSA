#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copying values
    int index = s;

    for(int i=0; i<len1; i++){
        first[i] = arr[index++];
    }

    index = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[index++];
    }

    //merge these arrays in sorted way
    int index1 = 0;
    int index2 = 0;
    index = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[index++] = first[index1++];
        }

        else{
            arr[index++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[index++] = first[index1++];
    }

    while(index2 < len2){
        arr[index++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e){
    if(s >= e){
        return;
    }

    int mid = (s+e)/2;

    //left call
    mergeSort(arr, s, mid);

    //right call
    mergeSort(arr, mid+1, e);

    //merge arrays
    merge(arr, s, e);
}

int main(){
    int arr[5] = {5,4,3,2,1};

    mergeSort(arr, 0, 4);

    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;
}