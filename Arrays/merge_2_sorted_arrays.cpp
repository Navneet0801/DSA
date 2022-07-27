#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeArray(vector<int> arr1, int m, vector<int> arr2, int n){
    vector<int> ans(m+n);

    int i = 0;
    int j = 0;
    int k = 0;

    while(i<m and j<n){
        if(arr1[i] < arr2[j]){
            ans[k++] = arr1[i++];
        }
        else{
            ans[k++] = arr2[j++];
        }
    }
    while(i<m){
        ans[k++] = arr1[i++];
    }
    while(j<n){
        ans[k++] = arr2[j++];
    }

    return ans;
}

int main(){
    vector<int> arr1 = {1,3,5,7,9};
    vector<int> arr2 = {2,4,6,8};

    vector<int> ans = mergeArray(arr1, 5, arr2, 4);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}

/*void mergeArray(int arr1[], int m, int arr2[], int n, int arr3[]){

    int i=0;
    int j=0;
    int k=0;

    while(i<m and j<n){
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }
    while(i<m){
        arr3[k++] = arr1[i++];
    }
    while(j<n){
        arr3[k++] = arr2[j++];
    }

}

int main(){
    int arr1[5] = {1,3,5,7,9};
    int arr2[4] = {2,4,6,8};
    int arr3[9] = {0};

    mergeArray(arr1, 5, arr2, 4, arr3);

    for(auto i: arr3){
        cout<<i<<" ";
    }

    return 0;
}*/