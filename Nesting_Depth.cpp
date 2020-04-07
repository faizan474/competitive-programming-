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
string s;
cin>>s;
string s_;
ll op=0,pre=0;

for(ll i=0;i<s.size();i++){
    ll k=s[i]-'0';
    if(k==pre){
        s_.push_back(s[i]);
    continue;}
    if(k<pre){
        while(k<pre){
            s_.push_back(')');
            pre--;  
        }
        s_.push_back(s[i]);
    }
    else if(k>pre){
        while(k>pre){
            s_.push_back('(');
            pre++;
        }
         s_.push_back(s[i]);
    }
}

while(pre){
    s_.push_back(')');pre--;

}
cout<<s_;
}




int main(){
   ll t=1;
  cin>>t;
  ll f=1;
    while(f<=t){
        cout<<"Case #"<<f<<": ";
        solve();
        cout<<endl;
        f++;
    }
    return 0;
}
