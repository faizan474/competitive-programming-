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
ll p[100005];
bool marked[100005];
int init[100005],goal[100005];
vll ans;
void dfs(ll u,ll par){
 
 for(ll v:adj[u]){
     if(v==par)continue;
     p[v]=u;
    // cout<<u<<"$$"<<v<<"^^"<<p[u]<<"@@"<<marked[p[par]]<<endl;
     if((marked[p[u]] && init[v]==goal[v])||(!marked[p[u]] && init[v]!=goal[v])){
          marked[v]=!marked[p[u]];
        ans.pb(v);
     }
     else if(marked[p[u]])
     marked[v]=true;
     
     dfs(v,u);
 }
}
 
void solve(){
ll n,u,v;cin>>n;
fr(i,1,n){cin>>u>>v,adj[u].pb(v),adj[v].pb(u);}
fr(i,1,n+1)cin>>init[i];
fr(i,1,n+1)cin>>goal[i];
mems(marked,false);
p[0]=0;
p[1]=0;
if(init[1]!=goal[1]){
 
    marked[1]=true;
    ans.pb(1);
}
dfs(1,0);
//fr(i,1,n+1)
//cout<<p[i]<<" "<<marked[i]<<endl;;
cout<<ans.size()<<endl;
for(ll v:ans)
cout<<v<<endl;
 
}
 
int main(){
    ll t=1;
//cin>>t;
    while(t--){
     solve();
   //  cout<<endl;
    }
    return 0;
}
 