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
/////////////////////////////////////////////////////////////////////////////////
ll inv(){
  ll k=mod-2;
  ll res=1;
  ll a=2;
  while(k){
    if(k&1)
    res=(res*a)%mod;

    a=a*a,a=a%mod;
    k=k/2;
  }
 // deb(res);
  return res;

}
void solve(){
    ll n;
    cin>>n;
    vll v(n);
    vll dp(1<<8);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    ll ans=0;
    ll nwxr;
    dp[0]=1;
    for(ll i=0;i<n;i++){

      vll tmp(1<<8);
      for(ll j=0;j<1<<8;j++){

        if(dp[j]!=0){
          ll nwxr=v[i]^j;
              tmp[nwxr]=(tmp[nwxr]+dp[j]%mod)%mod;
        }

      }

        for(ll j=0;j<1<<8;j++){
          dp[j]=(dp[j]+tmp[j])%mod;
        }
      //  dp[v[i]]++;
      
    }
    dp[0]--;
    
  ll inv2=inv();
  for(ll i=0;i<1<<8;i++){
     // deb(dp[i])
  ans=(ans+((((dp[i]*((dp[i]-1+mod)%mod))%mod)%mod)*inv2)%mod)%mod;
  }
  cout<<ans;
    
  
}
int main(){
    boost;
    ll t=1;
 // cin>>t;
    while(t--){
        solve();
       cout<<endl;
    }
    return 0;
}