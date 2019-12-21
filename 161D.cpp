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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const ll N=50005;
const ll L=500+1;
ll k;
ll ans=0;
vll adj[N];
ll lvl[N][L];
void dfs(ll u,ll par){
    lvl[u][0]=1;
    for(ll v:adj[u]){
        if(v==par)continue;
        dfs(v,u);
        //
        fr(i,1,k+1)
        ans+=lvl[v][i-1]*lvl[u][k-i];
        fr(i,1,k+1){  
           lvl[u][i]+=lvl[v][i-1];
        }
    
    }
}

void solve(){
    ll n;
    cin>>n>>k;
    for(ll i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs(1,0);
  //dfs2(1,0);
     cout<<ans<<endl;
    
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
