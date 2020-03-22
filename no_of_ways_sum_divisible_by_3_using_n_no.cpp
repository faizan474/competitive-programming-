// bismillah .....
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
void solve(){
                //  /_ _ _ _ _ _ _----_ _ _ _ _ _ _ /  //
             ll n,r,l;
             cin>>n>>l>>r;
             ll dp[n][3];
             mems(dp,0);
             dp[0][0]=r/3-(l%3==0?l/3-1:l/3);
             dp[0][1]=(r%3>=1?(r/3+1):r/3)-(l%3>1?(l/3+1):l/3);
             dp[0][2]=(r%3==2?(r/3+1):r/3)-l/3;

         //  cout<<dp[0][0]<<" "<<dp[0][1]<<" "<<dp[0][2]<<endl;

            for( ll i=1;i<n;i++){
                for(ll j=0;j<3;j++){
                     for(ll k=0;k<3;k++){
                         ll f=(j-k+3)%3;
                       dp[i][j]+=(dp[i-1][k]*dp[0][f])%mod;
                   }
                }
            }
           cout<<dp[n-1][0]%mod;


  }
int main(){
    ll t=1;
   // cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
