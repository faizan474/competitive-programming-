#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  mat vector<vector<ll>>
/////////////////////////////////////////////////////////////////////////////////////////////////
ll f[5000000];
ll inv[5000000];
ll p(ll n,ll k){
    ll res=1;
    while(k){
        if(k&1)
        res=(res*n)%mod;
        n=(n*n)%mod;
        k>>=1;
    }
    return res;
}
ll ncr(ll n,ll r){
ll ans=f[n];
ans=(ans*p(f[n-r],mod-2))%mod;
ans=(ans*p(f[r],mod-2))%mod;
//deb(ans)
return ans;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    // inclusion-exclusion-principle
    // |Ai|-|Ai^Aj|+|Ai^Aj^Ak|......
    ll kk=1;
    for(int i=1;i<=n;i++){
        ll pw=p(f[k],n-i);
        ans=ans+kk*(f[(n-i)*k+i]*ncr(n,i)%mod*p(pw,mod-2)%mod);
        ans=(ans+mod)%mod;
        kk*=-1;
       // deb(ans) ; 
           }
    cout<<ans;
}


int main(){
    ll t=1;
  cin>>t;
  f[0]=1,f[1]=1;
  inv[0]=1,inv[1]=1;
  fr(i,2,5000000){
    f[i]=(f[i-1]*i)%mod;
   // inv[i]=inv[mod%i]*(mod-i/mod)%mod;
    }
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}