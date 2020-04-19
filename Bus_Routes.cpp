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
#define mod 1000000000
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  mat vector<vector<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
ll H=0,W=0;
  pair<ll,ll> decodeString(const string& s, ll& i) {
      ll gg=0;
      pair<ll,ll>pi={gg,gg};
        while (i < s.length() && s[i] != ')') {
            if (!isdigit(s[i])){
                 if(s[i]=='E')
                 pi.ss++;
                 else if(s[i]=='W')
                 pi.ss--;
                 else if(s[i]=='N')
                 pi.ff--;
                 else pi.ff++; 
                 i++;
                }
            else {
                ll n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                n=n%mod;
                i++; // '['
                auto k=decodeString(s, i);
                i++; // ']'
                
                    ll fff=pi.ff+n*k.ff%mod;
                    fff=fff%mod;
                    ll sss=pi.ss+n*k.ss%mod;
                    sss=sss%mod;
                    pi={fff,sss};
            }
    
        }
        pi={pi.ff%mod,pi.ss%mod};
        return pi;
    }
void solve(){
  ll r=1,c=1;
  string str;
  cin>>str;
  ll i=0;
  auto p=decodeString(str,i);
  H=p.ff,W=p.ss;
  r=r+(H+1000000000)%1000000000;
  c=c+(W+1000000000)%1000000000;
  cout<<c<<" "<<r;


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