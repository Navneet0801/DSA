#include<iostream>
#include<vector>
using namespace std;

void right(vector<vector<int>>& mat, vector<int> &ans,int &rows, int &cols, int &rowe, int &cole){
    for(int k=cols; k<=cole and (rows <= rowe && cols <= cole); k++){
        ans.push_back(mat[rows][k]);
    }
    rows++;
}

void down(vector<vector<int>>& mat, vector<int> &ans,int &rows, int &cols, int &rowe, int &cole){
    for(int k=rows; k<=rowe and (rows <= rowe && cols <= cole); k++){
        ans.push_back(mat[k][cole]);
    }
    cole--;
}

void left(vector<vector<int>>& mat, vector<int> &ans,int &rows, int &cols, int &rowe, int &cole){
    for(int k=cole; k>=cols and (rows <= rowe && cols <= cole); k--){
        ans.push_back(mat[rowe][k]);
    }
    rowe--;
}

void up(vector<vector<int>>& mat, vector<int> &ans,int &rows, int &cols, int &rowe, int &cole){
    for(int k=rowe; k>=rows and (rows <= rowe && cols <= cole); k--){
        ans.push_back(mat[k][cols]);
    }
    cols++;
}

vector<int> spiralOrder(vector<vector<int>>& mat) {
    int rowe = mat.size()-1;
    int cole = mat[0].size()-1;
    int rows = 0;
    int cols = 0;
    vector<int> ans;
    while(rows <= rowe && cols <= cole){
        right(mat, ans, rows, cols, rowe, cole);
        down(mat, ans, rows, cols, rowe, cole);
        left(mat, ans, rows, cols, rowe, cole);
        up(mat, ans, rows, cols, rowe, cole);
    }   
    return ans;
}

int main(){
    vector<vector<int>> vec = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //[1,2,3,4,8,12,11,10,9,5,6,7]
    vector<int> ans = spiralOrder(vec);

    for(auto i:ans){
        cout<<i<<" ";
    }
}