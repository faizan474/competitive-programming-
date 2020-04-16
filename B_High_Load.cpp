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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(){
 ll n,k;
 cin>>n>>k;
 ll center=1;
 ll v=2;
 ll dd=2*((n-1)/k);
 if((n-1)%k==1)
 dd++;
 else if((n-1)%k>=2){
     dd+=2;
 }

 queue<pair<int,int>>q;
  cout<<dd<<"\n";
 for(int i=0;i<k;i++){
     cout<<1<<" "<<v<<endl;
     q.push({1,v});
     v++;
 }
 while(v<=n){
     auto tp=q.front();
     q.pop();
     cout<<tp.ss<<" "<<v<<endl;
     q.push({tp.ss,v});
     v++;
 }


}
int main(){
 // boost;
  ll t=1;
  //cin>>t;
  while(t--){
      solve();
      cout<<"\n";
  }
  
    return 0;
}
