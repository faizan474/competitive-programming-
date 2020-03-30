/*
t(n,k)=min{ max()}

dynamic programming O(n*K) //space
                    O(n*k*k) // time 
binary search approach  O(1)  // space 
                        O(n*log(sum(arr)));

*/

///////////////////////////////////////////////////////////////////
//////                   DP
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vll p(16);
ll find(vll &v,ll i,ll m){
  if(i<0 || m<0)
  return 1e11;



   ll sm=0;
  if(m==1){
    for(ll ii=i;ii>=0;ii--){
      sm+=v[ii];
    }
    return sm;
  }
   p[m]=0;
   ll ans=1e11;
  for(ll ii=i;ii>=0;ii--){
      sm+=v[ii];
      ans=min(ans,find(v,ii-1,m-1));
      p[m]=max(sm,p[m-1]);
        }
    return min(ans,p[m]);
  
}
void solve(){
	ll m,n;
	cin>>m>>n;
	vll v(n);
	for(auto &x:v)
	cin>>x;
	cout<<find(v,(ll)0,m);

}




int main(){
    ll t=1;
  /// cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}


////////////////////////////////////////////////////////////
//                 BINARY SEARCH
/*
int req(int arr[],int n,int f){
    int h=1,t=0;
    for(int i=0;i<n;i++){
    t+=arr[i];
    if(t>f)
    t=arr[i],h++;
    }
    return h;
}
    
int Min_Time(int arr[], int n, int k)
{ int l=0,h=0;
    for(int i=0;i<n;i++){
        l=max(l,arr[i]);
        h+=arr[i];
    }
    while(l<h){
        int mid=(l+h)/2;
        if(req(arr,n,mid)<=k)
        h=mid;
        else l=mid+1;
    }
   // cout<<req(arr,n,h)<<endl;;
    return h;
   
}

*/
