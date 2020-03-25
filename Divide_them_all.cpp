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

ll n,m;
bool isP(ll a, ll b, ll c) 
{ 
    return (c%__gcd(a,b) == 0); 
} 
void solution(ll a, ll b, ll c) 
{ 
    for (ll i = 0; i * a <= c; i++) { 
        if ((c - (i * a)) % b == 0) {
           ll bb=(c-(i*a))/b; 
            if(i<=n && i>=0 && bb<=m && bb>=0){
                cout<<"YES";
                return;
            }
        } 
    } 
    cout<<"NO";
  
} 
  


void solve(){
ll x,y;
cin>>n>>m>>x>>y;
ll k=n*x+m*y;
if(k%2!=0){
cout<<"NO";
return ;
}
if(n==0 || x==0){
    if(m%2==0 )
    cout<<"YES";
    else cout<<"NO";
    return ;
}
else if(m==0 || y==0){
    if(n%2==0)
    cout<<"YES";
    else cout<<"NO";
    return ;
}
if(isP(x,y,k/2)){
   solution(x,y,k/2);
//  cout<<"YES";

}
else cout<<"NO";

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