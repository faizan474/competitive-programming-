
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ull unsigned long long
#define fr(i,l,r) for(int i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
vll adj[2*100001];
bool vis[2*100001]={false};
bool mark[2*100001]={false};
ll par[2*100001];
ll cnt;
void dfs(int u){
vis[u]=true;
if(!mark[par[u]])
{mark[u]=true;cnt++;}
for(int i=0;i<adj[u].size();i++){
    if(!vis[adj[u][i]]){
        par[adj[u][i]]=u;
        dfs(adj[u][i]);
    }
}


}
void  solve(){
ll n,m;
cin>>n>>m;
cnt=0;
 ll u,v;
fr(i,0,m){
   
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}
par[u]=-1;
mark[u]=true;
 dfs(u);
 bool g=true;
if(cnt>(n/2))
g=false;
if(g)
cout<<cnt<<endl;
else 
cout<<n-cnt<<endl;

 for(int  i=1;i<=n;i++){
     if(mark[i]==g)
     cout<<i<<" ";
     adj[i].clear();
     vis[i]=false;
     mark[i]=false;
 }
 cout<<endl;

}
int main(){
    int t=1;
 cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

