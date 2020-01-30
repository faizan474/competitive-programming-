#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define deb(x) cout<<#x<<" "<<x<<endl;
#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
typedef vector<vector<ll>> matrix;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void solve(){
    ll n,m,k;cin>>n>>m>>k; 
     matrix dp(1<<(n+1),vll(22));
     vll v(n);
     fr(i,0,n)cin>>v[i];
     for(ll i=0;i<n;i++){
         dp[1<<i][i]=v[i];
     }
     matrix mat(n,vll(n,0));
     fr(i,0,k){
         ll u,v,x;
       
         cin>>u>>v>>x;
           u--,v--;
         mat[u][v]=x;
     }
     for(ll i=0;i<1<<n;i++){
         for(ll j=0;j<n;j++){
             if(i&(1<<j)){
                 for(ll k=0;k<n;k++){
                     if((i&(1<<k))==0){
                         dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+mat[j][k]+v[k]);
                         //   deb(dp[i|(1<<k)][k])
                     }
                 }
              
             }
         }
     }
     ll ans=0;
     for(ll i=0;i<1<<n;i++){
      //  cout<<__builtin_popcount(i)<<" ";
         if(__builtin_popcount(i)==m){
             for(int j=0;j<n;j++){
                ans=max(ans,dp[i][j]);
             }
         }
     }
     cout<<ans;

}
int main(){
    ll t=1;
//cin>>t;
    while(t--){
     solve();
   cout<<endl;
    }
    return 0;
}

