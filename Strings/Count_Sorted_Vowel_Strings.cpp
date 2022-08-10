#include<iostream>
#include<string>
#include<vector>
using namespace std;

int countVowelStrings(int n) {
    if(n == 1){
        return 5;
    }

    vector<string> s;
    string vowel = "aeiou";

    for(int i=0; i<vowel.length(); i++){
        for(int j=i; j<vowel.length(); j++){
            string temp = "";
            temp = temp + vowel[i] + vowel[j];
            cout<<temp<<endl;
            s.push_back(temp);
        }
    }
    return s.size();
}

int main(){
    cout << countVowelStrings(3) << endl;
}