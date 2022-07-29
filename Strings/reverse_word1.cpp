#include<bits/stdc++.h>
using namespace std;

void reverse(vector<char> &s, int l, int h){
    while(l<h){
        swap(s[l++], s[h--]);
    }
}

void reverseword(vector<char> &s){
    int p = 0;
    for(int i=0; i<=s.size(); i++){
        if(s[i] == ' ' || i == s.size()){
            reverse(s, p, i-1);
            p = i+1;
        }
    }
}

int main(){
    vector<char> ch = {'m','y',' ','n','a','m','e',' ','i','s',' ','N','a','v'};
    for(auto i:ch){
        cout<<i;
    }
    cout<<endl;
    reverseword(ch);
    for(auto i:ch){
        cout<<i;
    }

    return 0;
}