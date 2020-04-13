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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ll pw(ll a,ll k){
  
  ll res=1;
  while(k){
    if(k&1)
    res=(res*a)%mod;

    a=a*a,a=a%mod;
    k=k/2;
  }
  return res;

}
int main(){
  boost;

  ll n,k;
  cin>>n>>k;
   vll dp(k+1);

   for(ll i=1;i<=k;i++){
       
       dp[i]=(pw(k/i,n))%mod;
   }
   for(int i=k;i>1;i--){
       for(int j=1;j*j<=i;j++){
           if(i%j==0){
            dp[j]=(dp[j]-dp[i]+mod)%mod;
           if((i/j)!=j && j!=1){
            dp[i/j]=(dp[i/j]-dp[i]+mod)%mod;
           }
           }
       }
   }
   ll ans=0;
   ll sm=0;
    for(int i=k;i>=1;i--){
        ans=(ans+(i*dp[i])%mod)%mod;
    }
    
    cout<<ans;
    return 0;
}
