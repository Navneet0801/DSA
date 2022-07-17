#include <bits/stdc++.h>
using namespace std;
int main() {
    valarray<int> ans = {1,2,3,4,5,6,7,8,9,10};

    valarray<int> res = ans[slice(2,5,1)];

    for(auto i:res){
        cout<<i<<" ";
    }
    int k = 1;
    cout<<res[k++];
    return 0;
}
