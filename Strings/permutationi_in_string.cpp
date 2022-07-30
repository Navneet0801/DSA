#include<iostream>
#include<string>
using namespace std;

bool checkCount(int count1[26], int count2[26]){
    for(int i=0; i<26; i++){
        if(count1[i] != count2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int count1[26] = {0};

    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }

    //chack for 1st window

    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};

    while(i < windowSize && i < s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if(checkCount(count1, count2)){
        return true;
    }

    //changing window for further checking
    while(i < s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;

        index = s2[i-windowSize] - 'a';
        count2[index]--;
        
        i++;
        if(checkCount(count1, count2)){
        return true;
        }
    }
    return false;
}

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << checkInclusion(s1, s2);
}