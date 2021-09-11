// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const int mod=1000000007,inf=(9e17),MAX=1e6+5;
int n,m,i,j;

int dp[MAX];

void solve()
{
    cin>>n;
    dp[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=i-6;j<i;j++)
        if(j>=0)
        dp[i]=(dp[j]+dp[i])%mod;
        // cout<<i<<" "; deb(dp[i])        
    }
    cout<<dp[n];
}

signed main(){
   
//     It's going to be hard But Hard does not mean Impossible :)
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    // cin>>loser; 
    while(loser--){
        solve(); nl 
    }

    return 0;
}