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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void solve(){
    int n,p,k;
    cin>>n>>p>>k;
    vector<int>v(n+1);
    vector<pair<int,int>>dp(n+1);
    
    for(int i=1;i<=n;i++)
    cin>>v[i];
    sort(v.begin()+1,v.end());
    dp[0].ff=0;
    dp[0].ss=p;
    for(int i=1;i<=n;i++){
        ll idx=i-k;
        if(dp[i-1].ss>=v[i]){
            dp[i].ff=dp[i-1].ff+1;
            dp[i].ss=dp[i-1].ss-v[i];
        }
        else dp[i]=dp[i-1];
            if(idx>=0 && dp[idx].ss>=v[i]){
            dp[i].ff=dp[idx].ff+k;
            dp[i].ss=dp[idx].ss-(v[i]);

        }
//cout<<dp[i].ff<<"$$"<<dp[i].ss<<endl;
    }
    cout<<dp[n].ff;

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

