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
typedef vector<vector<ll>> matrix;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const ll K=2;
matrix mul(matrix &a,matrix &b){
    matrix c(K+1,vector<ll>(K+1));
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            for(int k=0;k<K;k++){
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]%mod)%mod;
                c[i][j]%=mod;
            }
        }
    }
    return c;
}
matrix powr(matrix &a,ll n){
    matrix ans(K+1,vector<ll>(K+1));
    for(int i=0;i<K;i++){
        ans[i][i]=1;
    }
    while(n){
        if(n&1)
        ans=mul(ans,a);
        a=mul(a,a);
        n=n>>1;
    }
    return ans;
}
void solve(){
 

   ll n ,m;
   cin>>n>>m;
   m%=mod;
    vector<ll>F1(K+1);
    F1[0]=m*m%mod;F1[1]=m;       // f(2)=2 ,f(1)=1;  F1={f(n-1),f(n-2)};
    
    matrix a(K+1,vector<ll>(K+1));              //a={{1,1},{1,0}}
    a[0][0]=(m-1+mod)%mod ,a[0][1]=(m-1+mod)%mod;
    a[1][0]=1, a[1][1]=0;
   
    
    if(n<=2){
        if(n==1)
        cout<<m;
        else cout<<m*m%mod;
        return ;
    }
    n-=2;
    a=powr(a,n);
    ll ans=0;
    for(int i=0;i<K;i++){
        ans+=(a[0][i]*F1[i])%mod;
        ans%=mod;
    }
    cout<<ans;
    

}

int main(){
    boost
    ll t=1;
cin>>t;
    while(t--){
     solve();
   cout<<endl;
    }
    return 0;
}

