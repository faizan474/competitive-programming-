#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll merge(vector<ll>&v,ll s,ll mid,ll e){
     ll i=s,j=mid+1;
  //   cout<<e<<" "<<s<<" ";
     ll arr[e-s+1];
     ll k=0,c=0;
    while(i<=mid && j<=e ){
        if(v[i]<=v[j]){
            arr[k++]=v[i++];
        }
        else {arr[k++]=v[j++];
        c+=mid-i+1;
        }
    }
    while(i<=mid){
        arr[k++]=v[i++];
    }
    while(j<=e){
        arr[k++]=v[j++];
    }
    for(int i=s;i<=e;i++){
        v[i]=arr[i-s];
    }
    return c;
}
ll find(vector<ll>&v,ll s,ll e){
    ll ans=0;
if(e>s){
   
    ll mid=(s+e)/2;
    // cout<<mid<<endl;
    ans+=find(v,s,mid);
    ans+=find(v,mid+1,e);
    ans+=merge(v,s,mid,e);
}
return ans;

    }
int main(){
  ll t;
  cin>>t;
  while(t--){
      ll n;
      cin>>n;
      vector<ll>v(n);
      for(ll &x:v)
      cin>>x;
      cout<<find(v,0,n-1)<<endl;
  }
}