#include<iostream>
#include<string>
using namespace std;

//with recursion
bool checkPalindrome(string s, int start, int end){
    if(start > end){
        return true;
    }

    if(s[start] != s[end]){
        return false;
    }
    return checkPalindrome(s, start+1, end-1);
}

//withour recursion
bool checkPalindrome1(string s){
    int n = s.length();
    for(int i=0; i<n/2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "abcaba";

    if(checkPalindrome1(s)){
        cout << "True (without recursion)" << endl;
    }
    else{
        cout << "False (without recursion)" << endl;
    }

    if(checkPalindrome(s, 0, s.length()-1)){
        cout << "True (with recursion)" << endl;
    }
    else{
        cout << "False (with recursion)" << endl;
    }
}