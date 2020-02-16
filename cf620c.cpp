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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
pair<ll,ll> find(pair<ll,ll>&p1,pair<ll,ll>&p2){
   if(p2.ff>p1.ss || p1.ff>p2.ss){
       return {1e10,1e10};
   }
   pair<ll,ll>ans;
    ans.ff=max(p1.ff,p2.ff);
    ans.ss=min(p1.ss,p2.ss);
    return ans;
}
void solve(){
   ll n,st;
   cin>>n>>st;
   mat v(n,vll(3));
   fr(i,0,n){
       fr(j,0,3)
       cin>>v[i][j];
   }
 pair<ll,ll>hv={st,st};
 ll pre=0;
 pair<ll,ll>pmax={1e10,1e10};
 for(ll i=0;i<n;i++){
     ll nxt=v[i][0]-pre;
     pre=v[i][0];
     hv={hv.ff-nxt,hv.ss+nxt};
     pair<ll,ll>req={v[i][1],v[i][2]};
      pair<ll,ll>intr=find(hv,req);
   //     cout<<intr.ff<<" "<<intr.ss<<endl;
      if(intr!=pmax){
          hv=intr;
      }
      else {
          cout<<"NO";
          return;
      }
     
 }
 cout<<"YES";
}


int main(){
    ll t=1;
 cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}