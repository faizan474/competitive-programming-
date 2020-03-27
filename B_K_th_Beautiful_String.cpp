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
#define  mat vector<vector<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll f(ll n,ll k){
	ll i=1,j=n-1;
	ll m;
   while(i<j){
	     m=(i+j)/2;
		if(m*(m+1)/2<k){
          i=m+1;		
		}
		else j=m;
	//	d2(i,j)
   }
 //  d1(j)
   return j;
}
void solve(){
	ll n,k;
	cin>>n>>k;
	ll kk=f(n,k);
	ll req=(kk*(kk+1))/2-kk;
	k-=req;


     //d1(req)
	ll  p1=n-1-kk;
	ll p2=n-1-k+1;
  //  d2(p1,p2);
	fr(i,0,n){
		if(i==p1 || i==p2){
			cout<<'b';
		}
		else cout<<'a';
		
	}
	
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
