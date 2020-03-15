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
ll dp[100005][101];
ll find(vll &v,ll n,ll prev,ll m){
    if(n<0)
    return 1;

   if(dp[n][prev]!=-1)
   return dp[n][prev];

     if(v[n]!=0){
         if(n!=v.size()-1 && abs(v[n+1]-v[n])>1)
            return dp[n][prev]=0;
         else 
            return dp[n][prev]=find(v,n-1,v[n],m)%mod;
     }
    ll ans=0;
    for(int i=1;i<=m;i++){
        bool ok=true;
        if(n!=v.size()-1  && abs(v[n+1]-i)>1)
            ok=false;
        if(ok){
            v[n]=i;
            ans=(ans+find(v,n-1,i,m))%mod;
            v[n]=0;
        }
    }
    dp[n][prev]=ans;
    return ans;

}
void solve(){
    mems(dp,-1);
   ll n,m;
   cin>>n>>m;
   vll v(n);
   fr(i,0,n)
   cin>>v[i];

   cout<<find(v,n-1,0,m)%mod;

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