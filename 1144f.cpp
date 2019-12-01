//https://codeforces.com/contest/1144/problem/F

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
vll  adj[100005];
//bool vis[100005];
ll   c[100005];
void addedge(ll u , ll v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}
bool isb(ll u){
     
    for(ll v:adj[u]){
        if(c[v]==-1){
            c[v]=c[u]^1;
            if(!isb(v))
            return false;
        }
       else if(c[v]==c[u])
            return false;
    }

    return true;

}
void solve(){
ll v,e;
fr(i,0,100005)
adj[i].clear();
vector<pair<ll,ll>>edg;
//mems(vis,false);
mems(c,-1);
cin>>v>>e;

  ll u,vv;
fr(i,0,e){
 cin>>u>>vv;
 edg.pbp(u,vv);
   addedge(u,vv);
    }
 ll flg=1;
 for(int i=1;i<=v;i++){
     if(c[i]==-1){
         c[i]=0;
         if(!isb(i)){
         flg=0;
         break;}
     }
 }
 if(flg==0)
 cout<<"NO";
 else {
     string str;
     fr(i,0,e){
         if(c[edg[i].ff]==0)
         str.pb('0');
         else str.pb('1');
     }
     cout<<"YES"<<"\n"<<str;
     
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
