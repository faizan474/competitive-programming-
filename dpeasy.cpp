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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(){
        ll n;
        cin>>n;
        vll v(3);
        fr(i,0,3)cin>>v[i];
        vll vv(n);
        fr(i,0,n)cin>>vv[i];
        mat dp(4,vll(n,-1e15));
        fr(i,0,n)
         dp[0][i]=0;
        for(ll i=1;i<=3;i++){
            for(ll j=0;j<n;j++){
                if(j==0)
                dp[i][j]=dp[i-1][j]+v[i-1]*vv[j];
                else 
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]+v[i-1]*vv[j]);
            }
        }
        cout<<dp[3][n-1];
        

}
int main(){
    ll t=1;
 //   cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
