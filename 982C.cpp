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
#define  mat vector<vector<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////long long int ncr(int n, int r){
const ll N=2*(1e5+5);
vll adj[N];
ll sz[N];
ll cnt=0;
ll dfs(ll u,ll par){
	sz[u]=1;
    for(ll x:adj[u]){
        if(x==par)continue;
        ll k=dfs(x,u);
        if(k%2==0)
        cnt++;
        sz[u]+=k;
    }
    return sz[u];
}
void solve(){
    ll n,u,v;
    cin>>n;
    fr(i,1,n){
        cin>>u>>v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
 ll f=1;
 for(int i=1;i<n+1;i++){
 	if(sz[i]==0){
 		if(dfs(i,-1)%2==1){
 			f=0;
 			break;
 		}
 	}
 }
if(f)
cout<<cnt;
else cout<<-1;
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