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
ll w[26];
ll find(ll *a,ll k){
    while(a[k]!=k){
        k=a[a[k]];
    }
    return k;
}
void Union(ll *a,ll u,ll v){
    ll uu=find(a,u);
    ll vv=find(a,v);
    if(uu==vv)return ;
    a[vv]=uu;
    w[vv]=0;
  //  w[uu]=1;
}



void solve(){
    
   ll n;cin>>n;
   vector<string>v(n);
   for(int i=0;i<n;i++)cin>>v[i];
   ll a[26];
   fr(i,0,26)
   a[i]=i,w[i]=0;
 //  memset(w,1,sizeof(w));

   for(int i=0;i<n;i++){
        w[find(a,v[i][0]-'a')]=1;
        
       for(int j=1;j<v[i].size();j++){
            w[find(a,v[i][j]-'a')]=1;
            Union(a,(ll)min(v[i][0]-'a',v[i][j]-'a'),(ll)max(v[i][0]-'a',v[i][j]-'a'));
           
       }
   }
  // for(int i=0;i<26;i++)
   //cout<<a[i]<<"$$$"<<w[i]<<endl;
   ll ans=0;
   for(int i=0;i<26;i++)
   ans+=w[i];
   cout<<ans;

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