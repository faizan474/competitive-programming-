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
#define mat  vector<vector<ll>> 
//////////////////////////////////////////////////////
const ll N=2*(1e5+5);
vll adj[N];
vll sze(N);
vll DFS;
vll ans(N);
void dfs(ll u,ll par){
  //  deb(u);
  sze[u]=1;
  DFS.pb(u);
  ans[u]=DFS.size()-1;
     for( ll x:adj[u]){
         if(x==par)continue;
         dfs(x,u);
         sze[u]+=sze[x];
    }
}


void solve(){
  ll n,u,v,q;
  cin>>n>>q;
  fr(i,2,n+1)
  cin>>u,adj[i].pb(u),adj[u].pb(i);
  fr(i,1,n)
  sort(adj[i].begin(),adj[i].end()); 
  dfs(1,-1);
  
  while(q--){
      ll k;
      cin>>v>>k;
      k--;
      if(k<sze[v])
      cout<<DFS[ans[v]+k]<<endl;
      else cout<<-1<<endl;
  }



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