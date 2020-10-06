#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define d1(x) cout<<#x<<" "<<x<<endl;
#define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define d2i(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;
#define all(v) v.begin(),v.end()
#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define pp pair<ll,ll>
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  mat vector<vector<ll>>
#define el cout<<'\n';
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(){
  ll n;
  cin>>n;
  vll v(n);
  for(ll &x:v)cin>>x;
  
   vll pre(n,-1e16),suff(n,-1e16);
   fr(i,0,n){
     if(i==0)
     pre[i]=v[i];
     else pre[i]=max(v[i],pre[i-1]+v[i]);
   }
   for(int i=n-1;i>=0;i--){
     if(i==n-1)
     suff[i]=v[i];
     else suff[i]=max(suff[i+1]+v[i],v[i]);
   }
   ll s_f=-1e16,curr=0;
   fr(i,0,n){
    curr+=v[i];
    curr=max(curr,v[i]);
    s_f=max(curr,s_f);
   }
   ll ans=s_f;
   for(int i=0;i<n;i++){

       if(i!=0 && v[i]+pre[i-1]==s_f)
            ans=max(ans,pre[i-1]);
       if(i!=n-1 &&  v[i]+suff[i+1]==s_f)
            ans=max(ans,suff[i+1]);
      if(i!=0 && i!=n-1 && suff[i+1]+v[i]+pre[i-1]==s_f)
            ans=max(ans,pre[i-1]+suff[i+1]);     
    
   }
   cout<<ans;
  
   

}
int main()
{
    ll t=1;
    cin>>t;
    while(t--)
    {
     solve();
     cout<<endl;
    }
	return 0;
}