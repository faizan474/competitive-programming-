// at coder beginner
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
const ll  maxx=1e10+5;
void solve(){
   ll n;
   cin>>n;
   if(n%2==1){
   cout<<0;return ;}
   n=n/2;

   ll ans1=1;
   ll k=2;
   while(k<=n){
       ans1+=n/k;
       k*=2;
   }
   ll kk=5,ans2=0;;
   while(kk<=n){
         ans2+=n/kk;
         kk=kk*5;
   }
   cout<<min(ans1,ans2)<<endl;
    
}
int main(){
    ll t=1;
//cin>>t;
    while(t--){

     solve();
    }
    return 0;
}
