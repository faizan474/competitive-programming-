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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void solve(){
    ll n=8;
    vll vv(n);
    fr(i,0,8)cin>>vv[i];
    ll k,u,v;
    cin>>k;
    ll a[9][9];
    memset(a,0,sizeof(a));
    while(k--){
  cin>>u>>v;u--,v--;
  a[u][v]=1;
  a[v][u]=1;
    }
    ll ans=0;

    for(ll i=0;i<1<<n;i++){
         ll flg=0;
         ll mx=0;
        for(ll j=0;j<n;j++){
        
            if(i&(1<<j)){
                for(ll kk=0;kk<n;kk++){
                     if(a[j][kk]==1 && (i&(1<<kk))){
                     flg=1;
                     break;
                     }
                }
                mx+=vv[j];
            }
        }
        if(!flg)
        ans=max(mx,ans);


    }
    cout<<ans<<endl;
 
 }   
int main(){
   // ll t=1;
//cin>>t;

     solve();
     cout<<endl;

    return 0;
}