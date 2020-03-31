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
#define  mat vector<vector<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll req(vll &v,ll n,ll m){
    ll c=0;
    if(m==0)
    return 1e11;
    for(int i=1;i<n;i++){
         if((v[i]-v[i-1])%m==0)
         c+=max((ll)0,(v[i]-v[i-1])/m-1);
         else c+=(v[i]-v[i-1])/m;
    }
return c;
}
void solve(){
ll n,k;
cin>>n>>k;
vll v(n);
ll j=0;
fr(i,0,n){
cin>>v[i];
if(i)
j=max(j,v[i]-v[i-1]);


}
int i=0;
while(i<j){
    ll m=(i+j)/2;

    if(req(v,n,m)<=k)
    j=m;
    else i=m+1;
    
}
cout<<j;


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
