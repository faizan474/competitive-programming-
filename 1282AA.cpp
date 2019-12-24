#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define deb(x) cout<<#x<<" "<<x<<endl;
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
ll a,b,c,r;
cin>>a>>b>>c>>r;
ll x,y;x=c-r,y=c+r;
if(a>b)
swap(a,b);
ll ans=0;
 ans+=b-a;
if(y<a || b<x){
cout<<ans;return ;}
x=max(a,x);
y=min(b,y);
//if(x<0 && y>0){
//    ans-=(y-x);
//}
//else ans-=(y-x+1);
ans-=(y-x);




cout<<ans;

//cout<<x<<"##"<<y<<endl;
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

