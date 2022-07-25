#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int k, int mid){
    int painterCount = 1;
    int boardSum = 0;
    
    for(int i=0; i<arr.size(); i++){
        if(boardSum + arr[i] <= mid){
            boardSum += arr[i];
        }
        else{
            painterCount++;
            if(painterCount > k || mid<arr[i]){
                return false;
            }
            boardSum = arr[i];
        }
    }
    return true;
}

pair<int, int> find(vector<int> boards){
    int maxi = -1;
    int sum = 0;
    
    for(int i=0; i<boards.size(); i++){
        maxi = max(maxi, boards[i]);
        sum += boards[i];
    }
    pair<int, int> ans;
    ans.first = maxi;
    ans.second = sum;
    
    return ans;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    pair<int, int> temp = find(boards);
    int min = temp.first;
    int max = temp.second;
    int res = -1;
    
    while(min <= max){
        int mid = (min+max)/2;
        
        if(isPossible(boards, k, mid)){
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
    vector<int> vec = {5, 5, 5, 5};

    cout<<findLargestMinDistance(vec, 2);

    return 0;
}