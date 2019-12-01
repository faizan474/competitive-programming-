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
ll n,inp;
cin>>n;
string str;
vector<string>v[101];

fr(i,0,n){
    cin>>inp>>str;

    if(i<n/2){
      v[inp].push_back("-");
    }
    else v[inp].push_back(str);

}

for(int i=0;i<101;i++){
     for(int j=0;j<v[i].size();j++)
     cout<<v[i][j]<<" ";
}
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