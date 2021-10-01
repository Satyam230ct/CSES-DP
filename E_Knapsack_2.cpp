// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const long long mod=1000000007,inf=(9e17),MAX=1e5+5;
int n,m,i,j;


int dp[102][MAX];
int wg[MAX],v[MAX];

// Time To make this problem through recursion

int helper(int idx,int value)
{
    if(value==0)return 0; // Means The value is going to be zero then
    if(idx==0 or value<0)return inf;

    if(dp[idx][value]!=-1)return dp[idx][value];

    // Time to exclude the element
    int ex=helper(idx-1,value);

    int incl=wg[idx]+helper(idx-1,value-v[idx]);

    return dp[idx][value]=min(ex,incl);
}

void solve()
{
    cin>>n; int w;  cin>>w;
    

    for(i=1;i<=n;i++)
    cin>>wg[i]>>v[i];

    int sum=accumulate(v+1,v+n+1,0LL);
    
    // Base Cases   
    for(int i=0;i<=n;i++)
    for(j=0;j<MAX;j++)dp[i][j]=-1;
  
    int ans=0;
    for(int i=sum;i>=0;i--)
    if(helper(n,i)<=w)
    {
        cout<<i;    return;
    }   
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