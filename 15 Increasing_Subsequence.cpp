// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const int mod=1000000007,inf=(9e17),MAX=2e5+5;
int n,m,i,j;



int get_best(map<int,int> &candidate,int v)
{
    auto it=candidate.lower_bound(v);  // lower->Strictly Increasing && Upper of Increasing means equality holds
    if(it==candidate.begin())return 0;
    it--; // Giving the best greatest among all candidate
    return it->second;
}
 
 
void insert(map<int,int> &candidate,int v,int adv)
{
    // Checking if there is alreadyb a guy having value v and adv greater than equal
    if(candidate[v]>=adv)return;    // No need to add this current element
 
    candidate[v]=adv; // Now we can add this in one of our possible asnwer
    // now time to delete the values which are greater than va nd giving less advantage than v
    auto it=candidate.find(v);
    it++;   // Gone to next element
    while (it!=candidate.end() and it->second<=adv)
    {
        auto tmp=it; it++;
        candidate.erase(tmp); 
    }
}
 
 
void solve()
{
    cin>>n;
    int a[n];   for(i=0;i<n;i++)cin>>a[i];
    int dp[n];  dp[0]=1;
    map<int,int> candidate;
    candidate[a[0]]=dp[0];
    for(i=1;i<n;i++)
    {
        dp[i]=1+get_best(candidate,a[i]);
        insert(candidate,a[i],dp[i]);
    }        
    cout<<*max_element(dp,dp+n);
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
/* TODO_problems:
   Graph: https://atcoder.jp/contests/abc218/tasks/abc218_f
   Binary Lifting (Yash H/W)- https://codeforces.com/contest/1516/problem/D
*/
