#include<iostream>
#include<string>
using namespace std;

void removeOccurrences(string &s, string part){
    int n = part.length();
    while(s.length() != 0  and  s.find(part) < s.length()){
        int m = s.find(part);
        s.erase(m, n);
    }
}

int main(){
    string s = "axxxxyyyyb";
    string part = "xy";

    removeOccurrences(s, part);

    cout<< s <<endl;

    return 0;
}