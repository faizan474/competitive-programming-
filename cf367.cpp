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
struct tr{
   int cnt;
   tr *node[2];
};
tr* newnode(){
    tr *Node=new tr;
    Node->cnt=1;
    fr(i,0,2)
    Node->node[i]=NULL;
    return Node;

}
void insrt(tr *root,ll val,ll sgn){
    tr *tmp=root;
   // cout<<(1<<0);
    for(ll i=30;i>=0;i--){
        ll k=val&(1<<i);
        if(k!=0)
        k=1;


        if(tmp->node[k]==NULL && sgn==1){
            tmp->node[k]=newnode();
        }
        else tmp->node[k]->cnt+=(1*sgn);

        tmp=tmp->node[k];

    }
}
ll query(tr *root,ll val){
    tr *tmp=root;
    ll curr=0;
    for(int i=30;i>=0;i--){
        ll k=val&(1<<i);
        if(k)
        k=1;
        
        if(tmp->node[1^k]!=NULL && tmp->node[1^k]->cnt>0){
            curr|=(1<<i);   
            tmp=tmp->node[1^k];       
        }
        else tmp=tmp->node[k];
    }
    return curr;
}

void solve(){
  ll q;
  cin>>q;
  tr *root=newnode();
  insrt(root,0,1);
  while(q--){

      char ch;ll x;
      cin>>ch>>x;
      if(ch=='+' && x!=0){

          insrt(root,x,1);
          
      }
      else if(ch=='-' && x!=0)
         insrt(root,x,-1);
      else if(ch=='?')
      cout<<query(root,x)<<endl;

  }
 

  }
int main(){
    ll t=1;
   // cin>>t;
    while(t--){
        solve();
       // cout<<endl;
    }
    return 0;
}