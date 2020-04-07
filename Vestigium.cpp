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
mat v(n,vll(n));
ll tr=0;
ll sm=(n*(n+1))/2;
ll c=0;
fr(i,0,n){
    ll tmp=0;
    set<ll>s;
    fr(j,0,n){
        cin>>v[i][j];
        if(i==j)
        tr+=v[i][j];
        s.insert(v[i][j]);
    }
    if(s.size()!=n)
    c++;

}
ll r=0;
fr(i,0,n){
     set<ll>s;
    fr(j,0,n){
    s.insert(v[j][i]);
    }
 if(s.size()!=n)
    r++;
}
cout<<tr<<" "<<c<<" "<<r;
}




int main(){
   ll t=1;
  cin>>t;
  ll f=1;
    while(f<=t){
        cout<<"Case #"<<f<<": ";
        solve();
        cout<<endl;
        f++;
    }
    return 0;
}
