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
vll  adj[105];
ll p[105];
ll in[105],out[105];
void dfs1(ll u,ll par){
   // in[u]=0;
    for(ll v:adj[u]){
        if(v==par)continue;
        dfs1(v,u);
        in[u]=max(in[u],in[v]+1);}
}
void dfs2(ll u,ll par){
    ll mx1=-1,mx2=-1;
    for(ll v:adj[u]){
        if(v==par)continue;
        if(in[v]>mx1)mx2=mx1,mx1=in[v];
        else if(in[v]>mx2)mx2=in[v];
    }
    for(ll v:adj[u]){
        if(v==par)continue;
        ll use=mx1;
        if(mx1==in[v])use=mx2;
        out[v]=max(out[u]+1,use!=-1?use+2:0);
        dfs2(v,u);
    }
}
 
ll  solve(){
ll n,u,v;cin>>n;
fr(i,1,n){cin>>u>>v,adj[u].pb(v),adj[v].pb(u);}
mems(out,0),mems(in,0);
dfs1(1,0);
dfs2(1,0);
ll mx=0;
fr(i,1,n+1)
adj[i].clear(),mx=max(mx,max(in[i],out[i]));
//cout<<in[i]<<"$$"<<out[i]<<endl
//cout<<mx<<endl;
//cout<<"#################\n";
return mx;
 
}
 
int main(){
    ll t=1;
cin>>t;
ll ans=0;
    while(t--){
     ans+=solve();
    // cout<<ans<<endl;
   
    }
    cout<<ans;
    return 0;
}
 