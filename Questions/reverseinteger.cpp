#include<bits/stdc++.h>

using namespace std;

int reverse(int x){
    int ans = 0;
    int res = abs(x);
    while(res>0){
        int temp = res%10;
        ans = ans*10 + temp;
        res = res/10;
    }
    if(x<0){
        return -1*ans;
    }
    return ans;
}

int main(){
    int a = -123;

    int b = reverse(a);
    cout<<b;

    return 0;
}