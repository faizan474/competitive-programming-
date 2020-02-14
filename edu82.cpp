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
vll adj[27];
int  vis[27];
stack<ll>s;
ll ld;
ll flg;
void dfs(ll u,ll par){
    vis[u]=2;
    ll ch=0;
    for(ll x:adj[u]){
        if(par==x)continue;
        if(vis[x]==-1){
            dfs(x,u);
            ch++;
        }
        else if(vis[x]==2){
            flg=0;
            return ;

        }

    }
    if(ch==0)
    ld=u;
    vis[u]=3;
    
}

void dfs2(ll u,ll par){
    vis[u]=2;
    ll  ch=0;
    for(ll x:adj[u]){
        if(par==x)continue;
        if(vis[x]==-1){
            dfs2(x,u);
            ch++;
        }

    }
    if(ch>1){
        flg=0;
        return ;
    }
s.push(u);
    vis[u]=3;
    
}

typedef pair<ll,ll> pp;
void solve(){
    mems(vis,-1);
    fr(i,0,27){
        adj[i].clear();
    }
    while(!s.empty()){s.pop();}
flg=1;

    string str;
    cin>>str;
    map<pp,ll>mp;
    for(ll i=1;i<str.size();i++){
        ll u=str[i]-'a';
        ll v=str[i-1]-'a';
        //cout<<u<<" "<<v<<endl;
        if(mp.find({u,v})==mp.end()){
        adj[u].pb(v);
        adj[v].pb(u);
        mp[{u,v}]=1;
        mp[{v,u}]=1;
        }
    }
    ll u=str[0]-'a';
    dfs(u,-1);
    if(flg){
    mems(vis,-1);
    dfs2(ld,-1);
    }
    if(flg){
        cout<<"YES"<<endl;
       vll arr(26);
    while(!s.empty()){
    cout<<(char)(s.top()+'a');
    arr[s.top()]=1;
    s.pop();
    }
    fr(i,0,26){
        if(arr[i]==0)
        cout<<(char)(i+'a');
    }

    }
    else cout<<"NO";

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