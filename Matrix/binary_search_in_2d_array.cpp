#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& m, int target) {
    int row = m.size();
    int col = m[0].size();

    int start = 0;
    int end = row*col - 1;

    while(start <= end){
        int mid = (start + end)/2;

        int element = m[mid/col][mid%col];
        if(element == target){
            return 1;
        }
        else if(element < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> vec = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    int target = 11;

    cout << searchMatrix(vec, target);
}