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
vll  adj[100005];
double ans[100005];

ll dfs(ll u,ll par){
    double chld=adj[u].size()-1;
    vll v;
    ans[u]=0;
    ll k=0;
    ll r=1;
    for(ll v:adj[u]){
        if(v==par)continue;
        chld++;
    }
    
    for(ll v:adj[u]){
        if(v==par)continue;
        
        k=dfs(v,u);
        r+=k;
        if(chld)
        ans[u]+=k/chld;
    }
    cout<<u<<"$$"<<ans[u]<<chld<<endl;;
    return r;

}

void solve(){
ll n,u,v;cin>>n;
mems(ans,0);
fr(i,1,n){cin>>u>>v,adj[u].pb(v),adj[v].pb(u);}
dfs(1,-1);
cout<<fixed;

cout<<setprecision(6)<<ans[1];

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

