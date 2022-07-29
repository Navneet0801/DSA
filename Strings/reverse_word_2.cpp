#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//approach 1 by letting a vector<string>

/*void reverse(vector<string> &ans){
    int l=0;
    int e=ans.size()-1;
    while(l<e){
        swap(ans[l++], ans[e--]);
    }
}

vector<string> reversestring(string &s){
    vector<string> ans;
    string str = "";

    for(int i=0; i<=s.length(); i++){
        if(s[i] == ' ' || i == s.length()){
            ans.push_back(str);
            str = "";
        }
        else{
            str += s[i];
        }
    }
    reverse(ans);
    return ans;
}

int main(){
    string s = "the sky is blue";

    cout<<s<<endl;

    vector<string> vec = reversestring(s);

    for(auto i:vec){
        cout<<i<<" ";
    }

    return 0;
}*/

//approach 2 without letting any vector<string>

int findIndex(string s, int start){
    while(start < s.length() && s[start] != ' '){
        start++;
    }
    return start;
}

string reverseWordString(string s){
    int start = 0;
    int end = 0;

    do{
        end = findIndex(s, start);
        reverse(s.begin()+start, s.begin()+end);
        start = end+1;
    }while (end < s.length());

    reverse(s.begin(), s.end());

    return s;
}

int main(){
    string s = "the sky is blue";

    string rs = reverseWordString(s);

    cout<< s << endl;
    cout<< rs << endl;

    return 0;
}