#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define d(x) cout<<#x<<" "<<x<<endl;
#define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define d2l(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;

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
const ll N=1e5+3;
ll n;
vll adj[N];
ll dis[N],low[N],par[N],vis[N],cnt[N];
ll wa=0,wb=0;
map<pair<ll,ll>,int>mp;
void dfs(ll u,ll t){
    vis[u]=1;
    dis[u]=low[u]=t+1;

    for(ll v:adj[u]){
        if(vis[v]==-1){
        
            par[v]=u;
            dfs(v,t+1);
            low[u]=min(low[u],low[v]);
            if(low[v]>dis[u])
            {  //bridge
                 if(mp.find({u,v})!=mp.end())
                 wa++;
               //  d2(u,v);
               //  d2(cnt[v],n-cnt[v])
            }
        }
        else if(par[u]!=v ){
            low[u]=min(low[u],dis[v]);
        }
    }
}
void init(){
    mems(vis,-1);
    mems(cnt,0);
    fr(i,0,N)
    low[i]=INT_MAX;
    par[1]=0;

}

void solve(){
    init();
    ll m,u,v;
    cin>>n>>m;
    vector<pair<ll,ll>>ed;
    fr(i,0,m){

    cin>>u>>v;adj[u].pb(v),adj[v].pb(u);
    ed.pbp(u,v);
    }
    ll ani;
    cin>>ani;
    fr(i,0,ani){
        ll k;
        cin>>k;k--;
        mp[ed[k]]++;
        mp[{ed[k].ss,ed[k].ff}]++;

    }
    for(ll i=1;i<=n;i++){
        if(vis[i]==-1)
          dfs(i,0);}
   cout<<wa;
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