// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";
 
const int mod=1000000007,inf=(9e17),MAX=2e5+5;
int n,m,i,j;
 
// States is we are at index this any by taking this how max we will get
 
int dp[MAX];
 
// Goint find the next greater day by using upper bound
int a[MAX],b[MAX],pv[MAX];
 
int helper(int index)
{
    if(index>n)return 0; 
    if(dp[index]!=-1)return dp[index];

    // skip this current index;
    int skp=helper(index+1); //,price);
    // Going to add this index
    auto to=upper_bound(a,a+n+1,b[index])-a;
    int tak=pv[index]+helper(to);
    return dp[index]=max(skp,tak);
}
 
void solve()
{
    cin>>n;
    vector<pair<pair<int,int>,int>> v(n); 
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>pv[i];
        v[i].first.first=a[i];  v[i].first.second=b[i];
        v[i].second=pv[i];
    }
    sort(v.begin(),v.end());
    for(i=1;i<=n;i++)
    {
        dp[i]=-1;
        a[i]=v[i-1].first.first;    b[i]=v[i-1].first.second;
        pv[i]=v[i-1].second;
    }
    a[0]=b[0]=pv[0]=0;
    cout<<helper(1);
}
 
signed main(){
   
//    Every Champion was a contender that refused to give up :)
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    // cin>>loser; 
    while(loser--){
        solve(); nl 
    }
    return 0;
}