#include<iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int pivot = arr[s];
    int count = 0;

    for(int i=s; i<=e; i++){
        if(arr[i] < pivot){
            count++;
        }
    }

    int pivotIndex = s+count;
    swap(arr[s], arr[pivotIndex]);

    int k = 0;
    int j = e;

    while(k < pivotIndex && j > pivotIndex){
        while(arr[k] <= pivot){
            k++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(k < pivotIndex && j > pivotIndex){
            swap(arr[k++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e){
    if(s >= e){
        return;
    }

    int p = partition(arr, s, e);

    //left partition call
    quickSort(arr, s, p-1);

    //right call
    quickSort(arr, p+1, e);
}

int main(){
    int arr[10] = {54,26,89,35,21,65,32,45,75,95};

    quickSort(arr, 0, 9);

    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;
}