#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define deb(x) cout<<#x<<" "<<x<<endl;
#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb2l(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;

#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 2e5+5;
const int LG = 20;
vll  adj[N];
int P[N][LG];
ll lvl[N];

void dfs(ll u,ll par){
    lvl[u]=lvl[par]+1;
    P[u][0]=par;

    for(ll v:adj[u]){
    if(v==par)continue;
    dfs(v,u);
    }

}
ll LCA(ll u,ll v){
if(lvl[u]<lvl[v])swap(u,v);
ll lg,i;
for( lg=0;1<<lg<=lvl[u];lg++);
lg--;
for( i=lg;i>=0;i--){
    if(lvl[u]-(1<<i)>=lvl[v])
      u=P[u][i];
}
if(u==v)
return u;

for( i=lg;i>=0;i--){
    if(P[u][i]!=-1 && P[u][i]!=P[v][i])
    u=P[u][i],v=P[v][i];
}
return P[u][0];


}
ll dis(ll u,ll v){
    ll lca=LCA(u,v);
 return (lvl[u]+lvl[v]-2*lvl[lca]);   
}
 
void  solve(){
ll n,u;cin>>n;
fr(i,2,n+1){
    cin>>u;
    adj[u].pb(i);adj[i].pb(u);
}
lvl[1]=0;
lvl[0]=-1;

//fr(i,1,n+1)cout<<lvl[i]<<" ";
//cout<<endl;
fr(i,0,n+2){
    fr(j,0,LG)P[i][j]=-1;
}
dfs(1,0);
fr(i,1,n+1){
    fr(j,1,LG){
        if(P[i][j-1]!=-1){
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}
ll l=1,r=1,ans=0;
for(int i=2;i<=n;i++){
    ll dis1=dis(i,l);
    ll dis2=dis(i,r);
    if(ans<dis1){
        r=i;
        ans=dis1;
    }
    else if(ans<dis2){
        l=i;
        ans=dis2;
    }
    cout<<ans<<" ";

    

}
 
}
 
int main(){
    ll t=1;
//cin>>t;
    while(t--){
    solve();

   
    }
//gg
    return 0;
}
 