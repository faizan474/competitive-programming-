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
#define pi pair<ll,ll>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   const int B_S=447;
struct el{
    int l,r,id;
};

ll mp[1000001];
bool comp(const el &a,const el &b){
    // if((a.l/B_S)!=(b.l/B_S))
    // return (a.l/B_S)<(b.l/B_S);
    // else (a.r)<(b.r);
   return make_pair(a.l/B_S,a.r)<make_pair(b.l/B_S,b.r);
}
int v[200000+1];
void add(ll &ans,int &l){
      //ll ans=0;
          ll cc=mp[v[l]];
          ans-=(cc*cc*v[l]);
          cc++;
          ans+=(cc*cc*v[l]);
          mp[v[l]]=cc;
}
void remove(ll &ans,int &l){
     // ll ans=0;
          ll cc=mp[v[l]];
          ans-=(cc*cc*v[l]);
          cc--;
          ans+=(cc*cc*v[l]);
          mp[v[l]]=cc;
}
void solve(){
    ll n,q;
    cin>>n>>q;
    fr(i,0,n)
    cin>>v[i];
    vector<el>vv(q);
     for(ll i=0;i<q;i++){
         cin>>vv[i].l>>vv[i].r;
         vv[i].l--,vv[i].r--;
         vv[i].id=i;
     }
     sort(all(vv),comp);
    vll ans(q);
    int l=0;
    int r=-1;
    ll ans1=0;
    for(auto &x:vv){
     //   d2(x.l,x.r)
        
        while(r<x.r){
            r++;
            add(ans1,r);
        }
        while(r>x.r){
            remove(ans1,r);
          r--;
        }
        while(l<x.l ){
         remove(ans1,l);
          l++;
        }

        while(l>x.l){
            l--;
            add(ans1,l);

        }
        
        
      ///  d2(l,r);
        
       ans[x.id]=ans1;
    }
    for(ll &x:ans)
    cout<<x<<"\n";
}
int main(){
 boost;
  ll t=1;
  //cin>>t;
  while(t--){
      solve();
    //  cout<<"\n";
  }
  
    return 0;
}
