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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(){
ll n;
cin>>n;
ll a[n][n];
vll v;;
fr(i,0,n){
    fr(j,0,n){
        cin>>a[i][j];
        if(i==j)
        v.pb(a[i][j]);
    }
}
//cout<<v.size()<<endl;
ll bits[n][17];
ll xr[n];
memset(xr,0,sizeof(xr));
ll q;
cin>>q;
while(q--){
    ll k,s,e,x;
    cin>>k>>s>>e>>x;
    s--,e--;
    xr[s]^=x;
    if(e+1<n)
    xr[e+1]^=x;
}
//for(int i=0;i<n;i++)
//cout<<xr[i]<<"$$";
//cout<<endl;
for(int i=1;i<n;i++){
    xr[i]^=xr[i-1];
}
//for(int i=0;i<n;i++)
//cout<<xr[i]<<"$$";
//cout<<endl;
ll ans=0;
for(int i=0;i<v.size();i++){
   // cout<<v[i]<<" "<<xr[i]<<endl;
    ans+=(v[i]^xr[i]);
}
cout<<ans;





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
