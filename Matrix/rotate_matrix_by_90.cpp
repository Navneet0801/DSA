#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& m) {
    int row = m.size();
    int col = m[0].size();
        
    //first transpose the matrix
    for(int i=0; i<row; i++){
        for(int j=0; j<i; j++){
            int temp  = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
        
    int start = 0;
    int end = row-1;
    //second flip the transposed matrix
    while(start <= end){
        for(int i=0; i<row; i++){
            int temp = m[i][start];
            m[i][start] = m[i][end];
            m[i][end] = temp;
            start++;
            end--;
        }
    }
}

int main(){
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};

    int row = m.size();
    int col = m[0].size();
    
    for(int i=0; i<row; i++){
        for(int j=0 ;j<col; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    rotate(m);

    cout<<"After rotating: "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0 ;j<col; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}