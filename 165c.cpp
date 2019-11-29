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

void  solve(){
    string str;
    ll k;
     cin>>k;
    cin>>str;
    ll n=str.size();
    
   
    if(k==0){
        ll tmp=0;
        ll ans=0;
        fr(i,0,n){
            if(str[i]=='1'){
                ans+=(tmp*(tmp+1))/2;
                tmp=0;
            }
            else tmp++;

        }
         ans+=(tmp*(tmp+1))/2;
         cout<<ans;
         return ;
    }
    vll pre(n);
    pre[0]=str[0]-'0';
    ll mx=pre[0];
    fr(i,1,n){
   pre[i]=str[i]-'0'+pre[i-1];
   mx=max(pre[i],mx);
   //m[tmp]++;
    }
    vll v(mx+1,0);
    v[0]=1;
    fr(i,0,n)
    v[pre[i]]++;
    ll ans=0;
    fr(i,k,mx+1){
    ans+=v[i]*v[i-k];
    }
    cout<<ans;
  
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