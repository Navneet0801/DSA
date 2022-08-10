#include<iostream>
#include<vector>
using namespace std;

void powerset(vector<int> nums, vector<int> output, int i, vector<vector<int> > &ans){
    if(i >= nums.size()){
        ans.push_back(output);
        return;
    }


    // output.pop_back();
    
    //exclusive
    powerset(nums, output, i+1, ans);
    
    /*for(auto k:output){
        cout << k << " ";
    }
    cout << endl;*/

    //inclusive 
    int element = nums[i];
    output.push_back(element);
    powerset(nums, output, i+1, ans);

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> output;
    powerset(nums, output, 0, ans);
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};

    vector<vector<int> > vec = subsets(arr);


    for(auto i:vec){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}