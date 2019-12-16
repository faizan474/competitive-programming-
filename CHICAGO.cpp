#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<pair<ll,double>>adj[107];
typedef pair<double,ll> pp;
void addedge(ll u , ll v,double d)
{
    adj[u].pbp(v,d);
    adj[v].pbp(u,d);
}
struct CustomCompare
{
    bool operator()(const pp& lhs, const pp& rhs)
    {
        return lhs.ff > rhs.ff;
    }
 
 
};
 
 
double dijkstra(ll u,ll n){
    bool vis[107]={false};
    mems(vis,false);
    double ans[107];
    multiset<pp,CustomCompare>s;
    s.insert({(double)1,1});
    vector<double>dis(107,-1);
    dis[1]=(double)1;
    while(!s.empty()){
        auto t=*s.begin();
        s.erase(s.begin());
        double w=t.ff;ll u=t.ss;
       // deb2(u,w);
        if(vis[u])continue;
 
        vis[u]=true;
        for(auto v:adj[u]){
            //deb2(v.ss,v.ff)
            //cout<<v.ss/100<<endl;
          //  deb(dis[v.ff])
            if(dis[v.ff]<dis[u]*(v.ss)){
                dis[v.ff]=dis[u]*(v.ss);
              //  deb(dis[v.ff])
                s.insert({dis[v.ff],v.ff});
            }
 
 
        }
 
    }
//fr(i,1,n+1)
//cout<<fixed<<setprecision(6)<<endl,cout<<dis[i]<<" ";
return dis[n];
}
void solve(){
	while(1){
    fr(i,0,107)
    adj[i].clear();
    ll n,m,u,v;
    double d;
    cin>>n;
    if(n==0)
    break;
    cin>>m;
 
    fr(i,0,m)
    cin>>u>>v>>d,addedge(u,v,d/(double)100);
    cout<<fixed;
    cout<<setprecision(6)<<dijkstra(1,n)*100<<" percent"<<endl;
	}
    
 
}
 
int main(){
     solve();
    return 0;
} 