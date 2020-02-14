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

ll find(ll mid,vll &v){
    ll n=v.size();
    ll ans=0;
    ll cnt=0;
    fr(i,0,n){ 
    if(v[i]==-1 )
    { ll rgt=0,lft=0;
     if(i!=0 && v[i-1]!=-1){
         lft=abs(mid-v[i-1]);
     }
     if(i!=n-1 && v[i+1]!=-1)
     rgt=abs(mid-v[i+1]);
        ans=max(ans,max(lft,rgt));
    }
    else {
        if(i!=0 && v[i-1]!=-1)
         ans=max(ans,abs(v[i]-v[i-1]));
    }
   
}
 return ans;
}


void solve(){
    ll n;
    cin>>n;
    vll v(n);
fr(i,0,n)
cin>>v[i];
ll ans=0,cnt=0;
fr(i,0,n){ 
    if(v[i]==-1)
    { ll rgt=0,lft=0;
     if(i!=0 && v[i-1]!=-1){
         lft=v[i-1],cnt++;
     }
     if(i!=n-1 && v[i+1]!=-1)
     rgt=v[i+1],cnt++;
        ans+=lft+rgt;
    }
}
ll f;
if(cnt)
 f=ans/cnt;
 //cout<<f<<endl;
 ll ans1=1e10;ll vv;
 ll c=find(f-1,v);
 if(f-1>=0 && ans1>c)
 ans1=c,vv=f-1;


 c=find(f,v);
 if(ans1>c){
    ans1=c,vv=f;
 }


 ans1=find(f+1,v);
 if(ans1>c){
     ans1=c,vv=f+1;
 }


cout<<ans1<<" "<<vv<<endl;

  }
int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
      //  cout<<endl;
    }
    return 0;
}