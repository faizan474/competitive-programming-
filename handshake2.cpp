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

 ll v[10][10];
pair<int,int> find(ll n){
    ll e=n%10;
    ll s;
    while(n){
        s=n%10;
        n/=10;
    }
    return {s,e};
}
int main(){
    ll n;
    cin>>n;
   
    
    for(int i=1;i<=n;i++){
      auto p=find(i);
      v[p.ff][p.ss]++;
    //  v[p.ss][p.ff]++;
    }
    ll ans =0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans+=v[i][j]*v[j][i];
        }
    }
    cout<<ans;
    return 0;
}