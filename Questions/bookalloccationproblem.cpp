#include<bits/stdc++.h>
using namespace std;

pair<int, int> find(vector<int> arr, int n){
    int sum = 0;
    int maxi = INT_MIN;

    for(auto i:arr){
        sum += i;
        maxi = max(maxi, i);
    }

    pair<int, int> ans;
    ans.first = maxi;
    ans.second = sum;

    return ans;
} 

bool isPossible(vector<int> arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;

            if(studentCount > m || mid < arr[i]){
                return false;
            }

            pageSum = arr[i];
        }
    }
    return true;
}

int allocatedPage(vector<int> arr, int n, int m){
    pair<int, int> temp = find(arr, n);
    int min = temp.first;
    int max = temp.second;
    int res = -1;

    while(min <= max){
        int mid = (min+max)/2;

        if(isPossible(arr, n, m, mid)){
            res = mid;
            max = mid-1;
        }
        else{
            min = mid+1;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {10,20,30,40};

    cout<<allocatedPage(arr, 4, 2);

    return 0;
}