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
#define  mat vector<vector<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const ll N=(1<<20);
ll tree[4*N];
ll flg;
void build(vll &v,ll l,ll r ,ll node){
	if(l==r){
		tree[node]=v[l];
		flg=1;
		return ;
	}
	ll mid=(l+r)/2;
	build(v,l,mid,2*node);
	build(v,mid+1,r,2*node+1);
   if(flg) 
   tree[node]=tree[2*node]|tree[2*node+1],flg^=1;
   else 
   tree[node]=tree[2*node]^tree[2*node+1],flg^=1;
}

void update(vll &v,ll l,ll r,ll idx, ll val,ll node){
	if(l==r){
		tree[node]=val;
	    flg=1;
		return ;
	}
	ll mid=(l+r)/2;
	if(idx<=mid)
		update(v,l,mid,idx,val,2*node);
	else
		update(v,mid+1,r,idx,val,2*node+1);
   if(flg) 
   tree[node]=tree[2*node]|tree[2*node+1],flg^=1;
   else 
   tree[node]=tree[2*node]^tree[2*node+1],flg^=1;
}


void solve(){
 
  ll n,q;
  cin>>n>>q;
  vll v(1<<n);
  fr(i,0,1<<n)
  cin>>v[i];
  build(v,0,(1<<n)-1,1);
  while(q--){
  	ll idx,val;
  	cin>>idx>>val;
  	idx--;
  	update(v,0,(1<<n)-1,idx,val,1);
  	cout<<tree[1]<<"\n";
  //	update(v,0,(1<<n)-1,idx,v[idx],1);
  }
  }
int main(){
    ll t=1;
   // cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}