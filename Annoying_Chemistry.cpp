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
    ll x,y,p,q;
    cin>>x>>y>>p>>q;
    ll t=p*y;
    ll tt=x*q;
     ll gcd=__gcd(t,tt);
     t/=gcd,tt/=gcd;
     ll b3=(t*x+tt*y)%(p+q);
    // gcd=__gcd((t*x+tt*y),(p+q));
     if(b3==0){
        b3=(t*x+tt*y)/(p+q);
     }
     else {
          b3=(t*x+tt*y);
        // deb(b3);
         int i=1;
        for(;i<1001 ;i++){
            if((b3*i)%(p+q)==0){
                t*=i;
                tt*=i;
               break;
            }
        }
        b3=(b3*i)/(p+q);
     }

     cout<<t<<" "<<tt<<" "<<b3<<endl;


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