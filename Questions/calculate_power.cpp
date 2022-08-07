#include<iostream>
using namespace std;

//with recursion
int answer1(int a, int b){
    if(b == 0){
        return a;
    }

    if(b%2 == 0){
        a = answer1(a, b/2);
    }
    else{
        a = a * answer1(a, b/2);
    }

    return a;
}


//without recursion
int answer(int a, int b){
    int ans = 1;
    for(int i=0; i<b; i++){
        ans = ans * a;
    }

    return ans;
}

int main(){

    //finding a^b
    int a = 6; 
    int b = 3;

    cout << answer(a, b) << endl;
    cout << answer1(a, b) << endl;
}