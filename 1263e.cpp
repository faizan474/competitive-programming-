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
struct tree{
    ll sm,mn,mx;
};
tree tr[2*1000005];
tree merge(tree a,tree b){
   tree c;
   c.sm=a.sm+b.sm;
   c.mx=max(a.mx,a.sm+b.mx);
   c.mn=min(a.mn,a.sm+b.mn);
return c;
}

void update(tree *tr,ll l,ll r,ll idx,ll node,ll val){
    if(idx<l || idx>r)
    return ;
    if(l==r){
        tr[node].sm=tr[node].mn=tr[node].mx=val;
        return ;
    }
    ll mid=(l+r)/2;
    update(tr,l,mid,idx, 2*node,val);
    update(tr,mid+1,r,idx,2*node+1,val);
    tr[node]=merge(tr[2*node],tr[2*node+1]);


}


void solve(){
ll n;
cin>>n;
string str;
cin>>str;
ll curr=1;

mems(tr,0);

for(char c:str){
    if(c=='R')
    curr++;
    else if(c=='L')
    curr= curr-1<1?1:curr-1;
    else if(c=='(')
        update(tr,1,n,curr,1,1);
    else if(c==')')
        update(tr,1,n,curr,1,-1);
    else 
        update(tr,1,n,curr,1,0);

    if(tr[1].sm!=0 || tr[1].mn<0)
        cout<<-1<<" ";
    else{
        cout<<tr[1].mx<<" ";
        }
    
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