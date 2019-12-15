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
vll adj[100005];
ll in[100005],out[100005],marked[100005];

void dfs1(ll u,ll par){
    in[u]=marked[u]?0:-1;
    for(ll v:adj[u]){
        if(v==par)continue;
        dfs1(v,u);
        if(in[v]!=-1)
        in[u]=max(in[u],in[v]+1);

    }
  //cout<<u<<"&&"<<in[u]<<endl;
}

void dfs2(ll u,ll par){
    ll mx1=-1,mx2=-1;
    // for sibling 
    for(ll v:adj[u]){
        if(v==par) continue;
        if(mx1<in[v]){mx2=mx1;mx1=in[v];}
        else if(in[v]>mx2) mx2=in[v];
    }


    for(ll v:adj[u]){
        if(v==par) continue;
        ll use=mx1;
        if(use==in[v])use=mx2;
        use=use!=-1?use+2:use;
        out[v]=max(out[u]!=-1?out[u]+1:-1,use);
        if(marked[v])
            out[v]=max(out[v],(ll)0);

        dfs2(v,u);
        
    }

}

void solve(){
ll n,m,d,u,v;cin>>n>>m>>d;
fr(i,0,m){cin>>u;marked[u]=1;}
fr(i,0,n-1){cin>>u>>v,adj[u].pb(v),adj[v].pb(u);} 
mems(out,-1);
dfs1(1,-1);
out[1]=marked[1]?0:-1;
dfs2(1,-1);
ll ans=0;

fr(i,1,n+1){
    ans+=in[i]<=d && out[i]<=d?1:0;
   // deb(ans);
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
