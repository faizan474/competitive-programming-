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

void solve(){
ll n;
cin>>n;
ll tot=(n*(n-1))/2;
map<pair<ll,ll>,int>mp;
ll p,c;
for(int i=0;i<10;i++){
    cin>>p;
    ll cnt=0;
    for(int j=0;j<9;j++){
        cin>>c;
        if(mp.find({p,c})==mp.end()){
            cnt++;
         mp[{p,c}]++;
         mp[{c,p}]++;
        }
    }
    tot-=cnt;
}
cout<<tot;

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