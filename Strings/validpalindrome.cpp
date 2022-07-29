#include<bits/stdc++.h>
using namespace std;

char tolower(char ch){
        if((ch >= 'a' and ch <= 'z') || (ch >= '0' and ch <= '9'))
            return ch;
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    
    bool isPalindrome(string s) {
        int l = 0;
        int h = s.length()-1;
        
        while(l<h){
            s[l] = tolower(s[l]);
            s[h] = tolower(s[h]);
            
            
            if((s[h] > 'z') && (s[l] < '0' || s[l] > '9')){
                l++;
            }
            
            else if(s[h] > 'z' && (s[l] < '0' || s[l] > '9')){
                h--;
            }
            
            else if(s[l] != s[h]){
                return false;
            }
            else{
                l++;
                h--;
            }
        }
        return true;
    }


    int main(){
        string s = "1b1";

        cout<<isPalindrome(s);

        return 0;
    }