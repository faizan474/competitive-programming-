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
    vll v(n+1);
    fr(i,1,n+1)cin>>v[i];
    ll xr=0;
    ll ans=0;
    map<ll,pair<ll,ll>>mp;
    for(ll i=1;i<n+1;i++){
     xr^=v[i];
     if(xr==0 && i%2==0){
         ans++;
     }
      if(mp.find(xr)!=mp.end()){
        if(i&1){
            ans+=mp[xr].ss;

        }
        else ans+=mp[xr].ff ;
        
      }
      if(i&1){
          mp[xr].ss+=1;
      }
      else mp[xr].ff+=1;
     
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