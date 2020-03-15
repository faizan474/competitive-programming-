// bismillah .....
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb2l(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;

#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 998244353
#define ff first
#define ss second
#define pp pair<ll,ll>
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  mat vector<vector<ll>>
 ll dp[105][10005];
 ll  ansp[105][10005];


ll  find(vector<pp>&v,ll idx,ll p){
    if(idx<0  || p<=0)
    return 0;
    
    ll &ans=dp[idx][p];
    if(ans!=-1)
    return ans;
    ll f=1;
    if(v[idx].ss<=p){
    ans=find(v,idx-1,p-v[idx].ss)+v[idx].ff-v[idx].ss;
    
    ansp[idx][p]=v[idx].ss+((idx==0)?0:ansp[idx-1][p-v[idx].ss]);

    f=0;
    }
    ll k=find(v,idx-1,p);
//    ll f=1;
if(!f && ans==k){
      ansp[idx][p]=min(ansp[idx][p],((idx==0)?0:ansp[idx-1][p]));
}
  else   if(ans<k){
    ans=k;
    ansp[idx][p]=((idx==0)?0:ansp[idx-1][p]);
    }
  //  if(f)
   // deb(idx)
     return ans;
    
}
void solve(){
    mems(dp,-1);
    mems(ansp,0);
    ll n,p;
    cin>>n>>p;
    vector<pp>v(n);
    fr(i,0,n)
    cin>>v[i].ff>>v[i].ss;
     ll k=find(v,n-1,p)+p;
     cout<<ansp[n-1][p]<<" "<<k;
}
int main(){
    boost;
    ll t=1;
   cin>>t;
    while(t--){
        solve();
       cout<<endl;
    }
    return 0;
}