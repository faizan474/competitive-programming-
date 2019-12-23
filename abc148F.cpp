// at coder beginner
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
const ll  maxx=1e5+5;
ll distT[maxx],distA[maxx];
vll adj[maxx];
bool used[maxx];
void dfs(ll u,ll par,ll *dist){
    dist[u]=dist[par]+1;
    for(ll v:adj[u]){
        if(v==par)continue;
        dfs(v,u,dist);
    }
}
// find usable vertex by comparing distT(i)>distA(i)
void dfs2(ll u,ll par){
    used[u]=true;
    for(ll v:adj[u]){
        if(v==par)continue;
        if(distT[v]>=distA[v])continue;
        dfs2(v,u);
    }
}
void solve(){
ll n,u,v;cin>>n>>u>>v;
ll x,y;
fr(i,1,n)cin>>x>>y,adj[x].pb(y),adj[y].pb(x);
distT[0]=-1,distA[0]=-1;
dfs(u,0,distT);
dfs(v,0,distA);
mems(used,false);
// trace path T can follow avoiding A
dfs2(u,0);
ll ans=0;
//since A has to catch as early as possible
for(ll i=1;i<=n;i++)
if(used[i]){
    ans=max(ans,distA[i]);
}
cout<<ans-1<<endl;
    
}
int main(){
    ll t=1;
//cin>>t;
    while(t--){

     solve();
    }
    return 0;
}
