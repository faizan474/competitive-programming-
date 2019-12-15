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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char mat[1002][1002];
ll n,m,k;
ll vis[1002][1002];
bool issafe(ll x,ll y){
    if(x>=0 && x<n && y>=0 && y<m && mat[x][y]=='.')
    return true;
    else return false ;
}
ll X[]={0,0,1,-1};
ll Y[]={-1,1,0,0};

bool  dfs(ll s1,ll s2,ll x,ll y,ll d){
    if(vis[x][y])
    {
        if(s1==x && s2==y && d>=k){
           // deb(d)
            return true;}
        else return false;

    }
    vis[x][y]=true;

for(ll i=0;i<4;i++){

    if(issafe(x+X[i],y+Y[i])){
        if(dfs(s1,s2,x+X[i],y+Y[i],d+1))
        return true;
        
    }
 

}
  vis[x][y]=false;
   return false ;
}


void solve(){
   cin>>n>>m;
  cin>>k;
    ll s1,s2;
   cin>>s1>>s2;
    s1--,s2--;
   fr(i,0,n){
       fr(j,0,m)
       cin>>mat[i][j];
   }
   
   //cout<<s1<<"##"<<s2;
  mems(vis,false);
  
   if(dfs(s1,s2,s1,s2,0))
   cout<<"YES";
   else cout<<"NO";

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
/*
5 5    
14
1 2
. . . * *
* . . . *
* . . . .
. * . . .
. * . . *
*/