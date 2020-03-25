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
ll dfs1(ll u){
    vis[u]=1;
    for(ll v:adj[u]){
        if(vis[v]==-1)
        cnt[u]+=dfs1(v);
    }
    cnt[u]++;
    return cnt[u];

}
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
                 if((n-cnt[v])%2==0 && cnt[v]%2==0 && n-cnt[v]!=0 && cnt[v]!=0)
                 wa++;
                 else if(n-cnt[v]!=0 && cnt[v]!=0)
                 wb++;
                
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
ll md(ll k){
    ll res=1;
    ll p=mod-2;
    while(p){
        if(p&1)
        res=(res*k)%mod;
        k=(k*k)%mod;
        p=p/2;
    }
    return res;
}
void solve(){
    init();
    ll m,u,v;
    cin>>n>>m;
    fr(i,0,m){
    cin>>u>>v;adj[u].pb(v),adj[v].pb(u);
    }
    cnt[1]=dfs1(1);
    mems(vis,-1);
    dfs(1,0);
    ll tot=wa+wb;
    ll gcd=__gcd(wa,tot);
   // d2(wa,wb)
    if(tot==0){
        cout<<0<<" "<<0;
        return;
    }
 //   d(md(m))
    cout<<((wa/gcd)*md(tot/gcd))%mod<<" ";
    gcd=__gcd(wb,tot);
    cout<<((wb/gcd)*md(tot/gcd))%mod;

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