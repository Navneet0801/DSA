#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
    string s;
    int count = 1;

    s = chars[0];
    
    if(chars.size() == 1){
        return 1;
    }

    for(int i=1; i<chars.size(); i++){
        if((chars[i] == chars[i-1])){
            count++;
        }
        else{
            if(count == 1){
                s = s + chars[i];
            }
            else{
                s = s + to_string(count);
                s = s + chars[i];
                count = 1;
            }
        }
    }
    if(count > 1){
        s = s + to_string(count);
    }
    chars.clear();
    for(auto i:s){
        chars.push_back(i);
    }

    return s.size();
}


int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};

    cout << compress(chars) <<endl;

    for(auto i:chars){
        cout << i << " ";
    }

    return 0;
}