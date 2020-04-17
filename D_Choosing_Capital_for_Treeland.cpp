#include<bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define d1(x) cout<<#x<<" "<<x<<endl;
#define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define d2i(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;
#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define all(v) v.begin(),v.end()
#define  mat vector<vector<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////;
const int N=2*1e5+5;
vector<pair<ll,ll>>g[N];
ll dfs(ll u,ll par){
    ll c=0;
    for(auto &x:g[u]){
        if(x.ff==par)
        continue;
        c+=x.ss;
        c+=dfs(x.ff,u);
    }
    return c;
}
map<ll,vll>mp;
void dfs2(ll u,ll par,ll k){
     mp[k].pb(u);
    for(auto &x:g[u]){
     if(x.ff==par)
     continue;
     ll kk=k;
     if(x.ss==1){
         kk--;
     }
     else kk++  ;
     dfs2(x.ff,u,kk);
    }
}
void solve(){
   ll n,u,v ;
   cin>>n;
   fr(i,1,n){
       cin>>u>>v;
       g[u].pbp(v,0);
       g[v].pbp(u,1);
   }
   ll k=dfs(1,0);
   // d1(k)
  //  mp[k].pb(1);
    dfs2(1,0,k);
    auto it=mp.begin();
    cout<<it->ff<<endl;
    sort(all(it->second));
    for(ll x:it->second){
        cout<<x<<" ";
    }
    }
int main(){
 boost;
  ll t=1;
  //cin>>t;
  while(t--){
      solve();
      cout<<"\n";
  }
  
    return 0;
}
