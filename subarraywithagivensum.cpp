// bismillah .....
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(){
    ll n;cin>>n;
    char ch;
    vll v(n);
    fr(i,0,n){
    cin>>ch;
    v[i]=ch=='1'?1:-1;
    }
    ll ans=0;
    map<ll,ll>mp;
    ll curr=0;
    for(ll i=0;i<n;i++){
        curr+=v[i];
        if(curr==0)
        ans=max(ans,i+1);
        if(mp.find(curr)!=mp.end()){
            ans=max(i-mp[curr],ans);
        }
        else mp[curr]=i;
    }
    cout<<ans<<endl;

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