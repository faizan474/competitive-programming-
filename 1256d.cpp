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
void solve(){
    ll n,k;
    cin>>n>>k;
    vll ans(n,1);vector<pair<ll,ll>> vv;
    string str;
    cin>>str;

    fr(i,0,n){
      
        if(str[i]=='0')
        vv.pbp(0,i+1);
    }
    ll i=0;
    ll curr=1;
    while(k>0 && i<vv.size()){
        ll s=min(vv[i].ss-curr,k);
            k-=s;
          vv[i].ss=vv[i].ss-s;
          curr=vv[i].ss+1;
       //   deb(curr)
        //  cout<<s<<" "<<k<<endl;
          i++;
    }
    for(int i=0;i<vv.size();i++){
        ans[vv[i].ss-1]=0;
    }
    fr(i,0,n)
    cout<<ans[i]<<"";
}
//0001110110
/*
1
10 12
0110111000
*/
int main(){
    ll t=1;
cin>>t;
    while(t--){
     solve();
     cout<<endl;
    }
    return 0;
}