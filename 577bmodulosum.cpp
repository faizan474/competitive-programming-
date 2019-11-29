#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

int main(){
    ll t=1;
  //cin>>t;
    while(t--){
     ll n,k;
     cin>>n>>k;
     ll  v[n];
     fr(i,0,n)
     {cin>>v[i];
     v[i]%=k;}
     if(n>k){
     cout<<"YES";return 0;
     }
  
    bool  dp[1003][1003];
    
    mems(dp,false);
    for (ll i = 1; i <= n; i++)
		{  dp[i][v[i-1]]=true;
     	for (ll j = 0; j < k; j++)
			{
		    dp[i][j]=(dp[i][j]||dp[i-1][j]||dp[i-1][(j-v[i-1]+k)%k]);		
        	}
		}
   //fr(i,1,n+1){
   //  fr(j,0,k)
   //  cout<<dp[i][j]<<" ";
   //  cout<<endl;
   //}
		if (dp[n][0])
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}