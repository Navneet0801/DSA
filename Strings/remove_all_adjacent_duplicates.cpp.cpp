#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

void cutting(string &s){
    
}


//app 1: time limit exceeded in long long long strings
/*string removeDuplicates(string s) {
    string ans = s;
    int i = 0;
    while(i<ans.length()){
        if(ans[i] == ans[i+1]){
            ans.erase(i, 2);
            i=0;
        }
        else{
            i++;
        }
    }
    return ans;
}*/

//app 2: using stacks
string removeDuplicates(string s) {
    stack<char> st;
    string ans = "";
        
    for(int i=0; i<s.length(); i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(s[i] != st.top()){
            st.push(s[i]);
        }
        else{
            st.pop();
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s = "abbaca";

    cout<<  s <<endl;

    string sr = removeDuplicates(s);

    cout<< sr <<endl;
}