// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const long long mod=1000000007,inf=(9e9),MAX=2e5+5;
int n,m,i,j;

// This is a standard bitmasking dp problem we can see easily constrant of n is upto 20

// Time 

#define pii pair<int,int>
#define rides first
#define occ_wt  second


pii dp[1048580]; // dp[i] Tells Number of min rides we are doing after including ith element

void solve()
{
    cin>>n; int x;  cin>>x;
    int wt[n];    for(i=0;i<n;i++)cin>>wt[i];

    // base case  
    dp[0]={0,inf};  // Means in 0th person 0 rides and have no occupied space;
    for(int mask=1;mask<(1<<n);mask++)
    {
        dp[mask]={inf,inf}; // Means Infinite ride and no occupied space now time to relasation
        // Trhough dp greedly min transition
        for(int j=0;j<n;j++)
        {
            if(!(mask&(1<<j))) // Means Jth element is not present in dp state so continue it
            continue;

            // Now the current mask is icludes this set bit
            // See previous transition value now
            auto pvs_tran=(mask^(1<<j));
            if(x-dp[pvs_tran].occ_wt>=wt[j]) // Means we can include the jth weight to answor without increasing the rides
            {
                dp[mask]=min(dp[mask],{dp[pvs_tran].rides,dp[pvs_tran].occ_wt+wt[j]});
            }
            else
            {
                dp[mask]=min(dp[mask],{dp[pvs_tran].rides+1,wt[j]});
            }
        }
    }
    cout<<dp[(1<<n)-1].rides<<" ";
}

signed main(){
   
//  Remember Someone out there is working 10x harder than you rn..
//    Chasing after the same goals...
//       So get up and go fucking work harder towards your goals.
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    // cin>>loser; 
    while(loser--){
        solve(); nl 
    }
    return 0;
}