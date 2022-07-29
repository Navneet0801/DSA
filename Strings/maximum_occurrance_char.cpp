#include<iostream>
#include<string>
#include<map>
using namespace std;


char maxoccurance(string s){
    char ch;
    int k=0;
    map<char, int> mp;
    for(char i='a'; i<='z'; i++){
        mp[i] = 0;
    }
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }

    // for(char i='a'; i<='z'; i++){
    //     cout<<i<<"->"<<mp[i]<<" ";
    // }

    for(char i='a'; i<='z'; i++){
        int prevk = k;
        if(mp[i] > k){
            k = mp[i];
            ch = i;
        }
        else if(prevk == k){
            continue;
        }
    }
    return ch;
}

int main(){
    string s = "pumpkini";

    cout<<maxoccurance(s);

    return 0;
}