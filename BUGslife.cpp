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
vll adj[2002];
ll color[2002];
bool vis[2002];
bool dfs(ll u){
    for(ll v:adj[u]){
        if(color[v]==-1){
            color[v]=1-color[u];
            if(!dfs(v))
            return false;
        }
        else if(color[v]==color[u])
        return false ;
    }
    return true;
}



void solve(){
    ll n,m,u,v;
     for(int i=0;i<=2001;i++)
      adj[i].clear();
    cin>>n>>m;
    fr(i,0,m)
    cin>>u>>v,adj[u].pb(v),adj[v].pb(u);
    mems(color,-1);
    ll flg=1;
    for(int i=0;i<=2001;i++)
    if(color[i]==-1 && !dfs(i)){
        flg=0;
    }
    if(flg==0)
    cout<<"Suspicious bugs found!"<<endl;
    else 
    cout<<"No suspicious bugs found!"<<endl;
  

}

int main(){
    ll t;
cin>>t;
ll k=1;
    while(k<=t){
        cout<<"Scenario #"<<k++<<":"<<endl;
     solve();
     
    }
    return 0;
}
