#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    // ll t, i, j, ans, l, r, q, odd, even, f, p, n;
    // string a;
    // cin>>t;
    
    // for(p=1; p<=t; p++)
    // {
    //     ans=0;
    //     cin>>n>>q;
    //     cin>>a;
        
    //     ll pre[n][26];
        
    //     for(i=0; i<n; i++)
    //     {
    //         if(i==0)
    //         {
    //             for(j=0; j<26; j++)
    //             {
    //                 if(a[i]-65==j)
    //                 {
    //                     pre[i][j]=1;
    //                 }else{
    //                     pre[i][j]=0;
    //                 }
    //             }
    //         }
    //         else{
    //             for(j=0; j<26; j++)
    //             {
    //                 if(a[i]-65==j)
    //                 {
    //                     pre[i][j]=pre[i-1][j]+1;
    //                 }else{
    //                     pre[i][j]=pre[i-1][j];
    //                 }
    //             }
    //         }
    //     }
        
    //     for(;q--;)
    //     {
    //         cin>>l>>r;
    //         l--;r--;
            
    //         odd=even=0;
            
    //         for(i=0; i<26; i++)
    //         {
    //             f=pre[r][i];
    //             if(l>0)
    //             f=f-pre[l-1][i];
                
    //             if((f%2)==0)
    //             even++;
    //             else
    //             odd++;
    //         }
            
    //         if((r-l+1)%2==0 && odd==0)
    //         ans++;
    //         else if((r-l+1)%2==1 && odd==1)
    //         ans++;
    //     }
        
    //     cout<<"Case #"<<p<<": "<<ans<<"\n";
    // }


    ll i,j,even,odd,t,n,q,l,r,z,f,ans;
    string s;
    cin>>t;
    ll pre[n][26]; //declare an array which store prefix sum

    for(z=0; z<t; z++){
        cin>>n>>q;
        cin>>s;

        for(i=0; i<n; i++){
            if(i==0){
                for(j=0; j<26; j++){
                    if(s[i]-65 == j){
                        pre[i][j] = 1;
                    }
                    else{
                        pre[i][j] = 0;
                    }
                }
            }
            else{
                for(j=0; j<26; j++){
                    if(s[i]-65 == j){
                        pre[i][j] = pre[i-1][j] + 1;
                    }
                    else{
                        pre[i][j] = pre[i-1][j];
                    }
                }
            }
        }
        while(q!=0){
            q--;
            cin>>l>>r;
            l--;r--;
            even = odd = 0;
            for(i=0; i<n; i++){
                f = pre[r][i];
                if(l>0)
                    f = pre[r][i] - pre[l-1][i];

                if(f%2 == 0)
                    even++;
                else
                    odd++;
            }
            if((r-l+1)%2 == 0 && odd == 0)
                ans++;
            else if((r-l+1) == 1 && odd == 1)
                ans++;
        }
        cout<<"Case #"<<z<<": "<<ans<<"\n";
    }
}