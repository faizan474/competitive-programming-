#include<bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
#define all(v) v.begin(),v.end()
#define  mat vector<vector<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    boost;
 ll t;
 cin>>t;
 while(t--){

      ll n,l,r;
      cin>>n>>l>>r;
      ll hv=0;
       vll ans;
       bool f=true;
       for(ll i=1;i<n && f;i++){
           hv+=2*(n-i);
           if(hv>=l){
           //     d1(hv)
               hv-=2*(n-i);
            //   d1(hv)
              for(ll ii=i;ii<n && f;ii++){
                  for(ll kk=ii+1;kk<=n && f;kk++){
                    hv++;
                  if(hv>=l && hv<=r)
                  ans.pb(ii);
                  hv++;
                  if(hv>=l && hv<=r)
                  ans.pb(kk);
                  if(hv>r)
                  f=0;
                  
                      
                  }
              }
              break;

           }
       }
       hv++;
       if(hv>=l && hv<=r)
       ans.pb(1);
    for(ll x:ans)
    cout<<x<<" ";
    cout<<endl;
 }

    return 0;
}
