#include<iostream>
#include<string>
using namespace std;

string replaceSpaces(string s){
    string ans = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            ans = ans + "@40";
        }
        else{
            ans = ans + s[i];
        }
    }
    return ans;
}

int main(){
    string s = "This is the string";

    cout<< s <<endl;

    string str = replaceSpaces(s);

    cout<< str <<endl;

    return 0;
}