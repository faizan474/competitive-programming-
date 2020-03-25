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
#define all(v) v.begin(),v.end()
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(){
ll n;
cin>>n;
vll v(n);
//unordered_map<ll,ll>mp;
ll f=0;
fr(i,0,n){
    cin>>v[i];
   // if(mp[v[i]]!=0){
  //     f=1; 
   // }
   // else mp[v[i]]++;
}
ll ans=1e10;
sort(all(v));
for(int i=1;i<n;i++){
    ans=min(ans,v[i]^v[i-1]);
}
cout<<ans;

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