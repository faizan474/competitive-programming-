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
ll dp[1505][51];
ll find(mat &v,ll p,ll id){
    if(p==0)
    return 0;
    if(id>=v.size())
    return 0;
      ll &ans=dp[p][id];
      if(ans!=-1)
      return ans;
    
    ans=find(v,p,id+1);
    for(int i=0;i<v[id].size();i++){
        if(p-i-1>=0)
       ans=max(ans,v[id][i]+find(v,p-i-1,id+1));
    }
    return ans;
}

void solve(){
    mems(dp,-1);
ll n,k,p;
cin>>n>>k>>p;
mat v(n,vll(k,0));
fr(i,0,n){
    fr(j,0,k){
    cin>>v[i][j];
    if(j==0)
    continue;
    v[i][j]+=v[i][j-1];
    }
}

cout<<find(v,p,0);




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
