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

ll a,b,c,d,x,y,x1,x2,y1,y2;
cin>>a>>b>>c>>d;
cin>>x>>y>>x1>>y1>>x2>>y2;
ll  xx=b-a;// + up 
ll yy=d-c;
  bool ok= true;
  x=xx+x;
  y=yy+y;
  //d2(x,y)
   if((a>0 || b>0) && abs(x2-x1)<1)
   ok =false;
    if((c>0 || d>0 ) && abs(y2-y1)<1)
   ok =false;
   
  if(x<=x2 && x>=x1 && y<=y2 && y>=y1 && ok)
  cout<<"Yes";
  else cout<<"No";


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
