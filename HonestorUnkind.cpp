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
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool istrue(ll bit,ll a[][16],ll n){
  for(int i=0;i<n;i++){
        if(bit&(1<<i)){
       //  cout<<bit<<"%%%"<<i<<endl;
            for(int j=0;j<n;j++){
           //     cout<<a[i][j]<<"-------"<<(bit&(1<<j))<<endl;
                 if(a[i][j]==1 && !(bit&(1<<j))){
                     return false ;
                 }
                 if(a[i][j]==0 && (bit&(1<<j))){
                     return false;
                 }
             }
        }
  }
return true;
}
void solve(){
ll n;
cin>>n;
ll a[16][16];
mems(a,-1);
for(ll i=0;i<n;i++){
    ll k,x,y;
    cin>>k;
    for(int j=0;j<k;j++){
        cin>>x>>y;
        x--;
        a[i][x]=y;

    }

}
ll ans=0;
for(ll bit=0;bit<(1<<n);bit++){

    if(istrue(bit,a,n))
    { 
        ll cnt=0;
        for(int i=0;i<n;i++)
        if(bit&(1<<i))cnt++;
     //   deb(cnt);
   ans=max(ans,cnt);
    }

}
cout<<ans<<endl;
  
}

int main(){
    ll t=1;
//cin>>t;
    while(t--){
     solve();
 //    cout<<endl;
    }
    return 0;
}

