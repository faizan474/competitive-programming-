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
#define mod 1000000009
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  mat vector<vector<ll>>
/////////////////////////////////////////////////////////////////////////////////////////////////
ll dp[301][301][2];
ll find(string &a,string &b,ll i,ll j,bool tt){
  if(i>j)
  return 0;
  if(i==j){
    if(tt)
    return a[i]=='1';
    else 
    return a[i]=='0';
  }
  ll &ans=dp[i][j][tt],t=0,f=0;
  if(ans!=-1)
  return ans;
  ans=0;
  //ll t_tl=0,t_tr=0,t_fl=0,t_fr=0,t=0,f=0;
  for(ll k=i+1;k<=j;k++){
    ll tl=find(a,b,i,k-1,1);
    ll fl=find(a,b,i,k-1,0);
    ll tr=find(a,b,k,j,1);
    ll fr=find(a,b,k,j,0);
    ll tot=((tl+fl)%mod*(tr+fr))%mod;
  
    if(b[k-1]=='a'){
      t=t+(tl*tr)%mod; 
      f=f+(tot-(tl*tr)%mod+mod)%mod;
    }
    else if(b[k-1]=='x'){
      t=t+((tl*fr)%mod+(fl*tr)%mod)%mod;
      f=f+((tl*tr)%mod+(fl*fr)%mod)%mod;

    }
    else if(b[k-1]=='o'){
      t=t+(tot-(fl*fr)%mod+mod)%mod;
      f=f+(fl*fr)%mod;
    }
    f%=mod;
    t%=mod;
  }
    if(tt)
    ans= t;
    else ans=f;
    return ans; 

}
void solve(){
  mems(dp,-1);
  string s1,s2;
  cin>>s1>>s2;
  //ll f=find(s1,s2,0,s1.size()-1,0);
  ll q;
  cin>>q;
  while(q--){
    ll a,b;string d;
    bool k;
    cin>>a>>b>>d;
    a--,b--;
    if(d=="true")
     k=1;
     else k=0;
    cout<<find(s1,s2,a,b,k)<<endl;
  }


  
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