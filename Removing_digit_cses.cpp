// bismillah .....        
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb2l(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;
 
#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pp pair<ll,ll>
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  mat vector<vector<ll>>
ll dp[1000005];
 
ll find ( ll n){
    if(n<0)
    return 1e11;
    if(n==0)
    return 0;
    if(n/10==0)
     return 1;
     if(dp[n]!=-1)
     return dp[n];
     ll k=n;
     ll ans=1e10;
     while(k){
         if(k%10==0){
             k/=10;
             continue;
         }
         ans=min(ans,find(n-k%10)+1);
         k/=10;
         }
         dp[n]=ans;
         return ans;
     }
void solve(){
    mems(dp,-1);
    ll n;
    cin>>n;
    cout<<find(n);
}
int main(){
    boost;
    ll t=1;
//  cin>>t;
    while(t--){
        solve();
       cout<<endl;
    }
    return 0;
}