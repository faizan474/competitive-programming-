//https://codeforces.com/problemset/problem/835/C
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
ll a[11][102][102];
ll dp[11][101][101]; // no of star having brightness c a less than equal to x and y;

// block query 
ll find(ll p,ll x,ll y){

    if( x<=0 || y<=0)
    return 0;

    ll &ans=dp[p][x][y];
    if(ans!=-1)
    return ans;
// ans=0; 
//deb(ans)
ans=0;
    ans=find(p,x-1,y)+find(p,x,y-1)-find(p,x-1,y-1)+a[p][x][y];
 // deb(ans)  
        return ans;
    
}

void solve(){
    ll n,q,c,x,y,si;
  mems(dp,-1);
  mems(a,0);
    cin>>n>>q>>c;
    fr(i,0,n){
        cin>>x>>y>>si;
        a[si][x][y]+=1;
    }

    for(ll i=0;i<=c;i++){
     dp[i][100][100]=find(i,100,100);
        }

while(q--){
    ll ti,x1,x2,y1,y2;
    cin>>ti>>x1>>x2>>y1>>y2;
    ll ans=0;
    for(ll i=0;i<=c;i++)
    ans+=(find(i,x2,y2)-find(i,x1-1,y2)-find(i,x2,y1-1)+find(i,x1-1,y1-1));
    cout<<ans<<endl;
}

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
