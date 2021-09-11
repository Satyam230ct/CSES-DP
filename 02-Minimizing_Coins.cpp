// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const int mod=1000000007,inf=(9e17),MAX=1e6+5;
int n,m,i,j;

// dp[sum]

int dp[1000006];
int c[MAX];
int top_down_helper(int sum)
{
    if(sum==0)return 0;
    if(sum<0)return INT_MAX;
    if(dp[sum]!=-1)return dp[sum];
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    if(sum-c[i]>=0)
    {
        int sub_problems=top_down_helper(sum-c[i]);
        res=min(res,sub_problems+1);
    }
    return dp[sum]=res;
}

void solve()
{
    int sum;
    cin>>n>>sum;
    for(i=0;i<n;i++)cin>>c[i];

//-----------Top Down Approach--------------------

    memset(dp,-1,sizeof dp);
    top_down_helper(sum);
    if(dp[sum]==INT_MAX)dp[sum]=-1;
    cout<<dp[sum];

//---------------------------------------------------

    // Bottom-up approach
    memset(dp,0,sizeof dp);
    dp[0]=0;
    for(int s=1;s<=sum;s++)
    {
        dp[s]=INT_MAX;
        for(int i=0;i<n;i++)
        if(s-c[i]>=0)
        dp[s]=min(dp[s],dp[s-c[i]]+1);
    }
    if(dp[sum]==INT_MAX)dp[sum]=-1;
    cout<<dp[sum];
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