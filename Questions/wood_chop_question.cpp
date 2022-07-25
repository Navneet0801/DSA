#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> arr, int k, int mid){
    int wood = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] < mid){  
            continue;
        }
        wood += arr[i] - mid;
    }
    if(wood < k){
        return false;
    }
    return true;
}
int maxarr(vector<int> arr){
	int mx = INT32_MIN;
	for(int i=0; i<arr.size(); i++){
		mx = max(arr[i],mx);
	}
	return mx;
}
int setHeight(vector<int> arr, int k){
    int min = 0;
    int max = maxarr(arr);
    int ans=0;
    while(min <= max){
        int mid = (min+max)/2;
        if (isPossible(arr, k , mid)){
            ans = mid;
            min = mid+1; 
        }
        else{
            max = mid-1;
        }
    }
    return ans; 
}

int main(){
    vector<int> vec = {20,15,10,17};
    cout<<setHeight(vec, 7);
return 0;
}