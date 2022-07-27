#include<iostream>
#include<vector>
using namespace std;

void reversearray(vector<int> &vec){
    int s = 0;
    int e = vec.size()-1;

    while(s<e){
        swap(vec[s], vec[e]);
        s++;
        e--;
    }
}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,0};

    for(auto i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    
    reversearray(vec);

    for(auto i:vec){
        cout<<i<<" ";
    }

    return 0;
}