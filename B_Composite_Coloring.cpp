#include<bits/stdc++.h>
using namespace std;
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
 ll n;
 cin>>n;
 vll v(n);
 vll ans(n,-1);
 fr(i,0,n)
 cin>>v[i];
 
 
 bool p[1000];
 mems(p,true);
 for(int i=2;i*i<=1000;i++){
      if(p[i]){
          for(ll j=2*i;j<=1000;j+=2){
              p[j]=false;
          }
      }
 }
 vll pp;
 fr(i,2,1001)
 if(p[i])
 pp.pb(i);

 ll c=1;
 for(int j=0;j<pp.size();j++){
    bool ok =false;
 for(int i=0;i<n;i++){
     if(ans[i]==-1 && v[i]%pp[j]==0){
      ans[i]=c;
      ok=true;
     }
 }
 if(ok)
 c++;
 }
 cout<<c-1<<endl;
 for(auto &x:ans)
 cout<<x<<" ";




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
