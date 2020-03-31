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


struct node{
    int cnt;
    node *child[26];
    node(){
                    cnt=0;
    
        for(int i=0;i<26;i++){

            child[i]=NULL;
        }
    }
};
void add (string &s,node* root){
    node *temp=root;
    for(int i=0;i<s.size();i++){
         int k=s[i]-'A';
         if(temp->child[k]==NULL){
             temp->child[k]=new node();
         }
        temp=temp->child[k];
        temp->cnt=temp->cnt+1;
        //cout<<temp->cnt<<endl;
    }
}
ll find(node *root,ll k){

      ll ans=0;
      for(int i=0;i<26;i++){
          if(root->child[i]!=NULL){
           //   d1((root->child[i]->cnt))
              ans+=find(root->child[i],k)+(root->child[i]->cnt)/k;
          }
          
      }
      return ans;
}
void solve(){

  node *root=new node();
  ll n,k;
  cin>>n>>k;
  string s;
  fr(i,0,n){
  cin>>s;
//d1(s)
  add(s,root);}

 cout<<find(root,k);

  
}




int main(){
    ll t=1;
  cin>>t;
  ll f=1;
    while(f<=t){
        cout<<"Case #"<<f<<": ";
        solve();
        cout<<endl;
        f++;
    }

    return 0;
}
