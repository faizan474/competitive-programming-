#include<bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
#define el cout<<'\n';
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll dp[1379][53][53];
ll  fnd(ll sum,ll dig,ll val){
    if (sum==0 && dig==0)
    return 1;
    else if (sum<=0 || dig<=0 || val<=0)
    return 0;
    
    ll &ans=dp[sum][dig][val];
    if(ans!=-1) return ans;
     ans=fnd(sum-val,dig-1,val-1)+fnd(sum,dig,val-1);
    return ans;

}

/// 26+26 52+1 caharter  
int main(){
 //cout<<26*2-1<<endl;
    mems(dp,-1);
   ll k=fnd(1378,52,52);
 ll t;
    ll i=1;
 cin>>t;
    while(t--){
      cout<<"Case "<<i++<<": ";
        ll n,m;
        cin>>m>>n;
       cout<<fnd(n,m,52);
       el;

        }
    return 0;
}
