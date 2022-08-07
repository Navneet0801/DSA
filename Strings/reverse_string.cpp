#include<iostream>
#include<string>
using namespace std;

//with recursion
string reverseStringr(string &s, int start, int end){
    if(start > end){
        return s;
    }

    swap(s[start], s[end]);

    reverseStringr(s, start+1, end-1);
    return s;
}

//without recursion
string reverseString(string s){

    string ans = "";
    int st = 0;
    int e = s.length()-1;

    while(st<=e){
        swap(s[st++], s[e--]);
    }

    ans = s;
    return ans;



}

int main(){
    string s = "abcdef";

    cout << s << endl;

    string rs = reverseString(s);

    cout << rs << endl;

    string rs1 = reverseStringr(s, 0, s.length()-1);

    cout << rs1 << endl;
}