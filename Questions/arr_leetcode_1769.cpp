#include<bits/stdc++.h>
using namespace std;

vector<int> minOperations(string boxes){
    vector<int> ans;
    for(int i=0; i<boxes.length(); i++){
        int count = 0;
        for(int j=0; j<boxes.length(); j++){
            if(i == j)  continue;
            if(boxes[j] == '1')   count += abs(i-j);  
        }
        ans.push_back(count);
    }
    return ans;
}

int main(){
    string s;
    cin>>s;

    vector<int> vec = minOperations(s);
    for(auto i:vec){
        cout<<i<<" ";
    }

    return 0;
}