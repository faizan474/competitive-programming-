//g++  5.4.0

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<ll>>dp(151,vector<ll>(151,-1));
ll find(ll n,ll k){
    if(k==0)
        return 0;
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    ll ans=0;
    if(dp[n][k-1]==-1)
        ans+=find(n,k-1);
    else ans+=dp[n][k-1];
    if(n-k>=0 && dp[n-k][k]==-1)
        ans+=find(n-k,k);
    else if(n-k>=0)
        ans+=dp[n-k][k];
        
        dp[n][k]=ans;
        return ans;
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        for(int i=0;i<=150;i++){
            for(int j=0;j<=150;j++){
                dp[i][j]=-1;
            }
        }
        cin>>n>>k;
       cout<< find(k,n)<<endl;;
    }
    
}