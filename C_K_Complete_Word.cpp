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
#define all(v) v.begin(),v.end()
#define  mat vector<vector<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(){
ll n,k;
cin>>n>>k;
string s;
cin>>s;
mat h(k,vll(26));
for(int i=0;i<n;i++){
    ll kk=s[i]-'a';
    h[i%k][kk]++;
}
ll ans;

int i=0,j=k-1;
ll f=n/k;

ans=0;

while(i<=j){
    ll mn=1e11;
    
    for(int ii=0;ii<26;ii++){
    for(int jj=0;jj<26;jj++){
        ll kkk=2*f;
        if(i==j){

                mn=min(mn,f-h[i][ii]);
            }
        else 
          if(ii==jj)
          mn=min(kkk-(h[i][ii]+h[j][jj]),mn);
          else 
           mn=min(mn,kkk-max(h[i][ii],h[j][jj]));
           
    }
    }
    ans+=mn;

  //  ans-=min()
    i++,j--;
}
cout<<ans;
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
