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
void solve(){
  ll n;
  cin>>n;
  vll v(n);       ;
 for(auto i = 0;i<n;i++)
    cin>>v[i];
  ll   ansm= 0;
 vll ans(n);
       for(auto i=0;i<n;i++)
       {

           if(i==0)
           {ans[i]=1;continue;
           }
           else if(v[i]==v[i-1]) ans[i]=ans[i-1];
           else ans[i] = ans[i-1]==1?2:1;
        ansm= max(ansm,ans[i]);
       }

       if(ans[0]==ans[n-1] && v[0]!=v[n-1])
       {
           for(auto i = n-1;i>=0;i--)
           {
               if(i==0){ans[i] = 3;ansm=3;
                break;}
               if(v[i]!=v[i-1])
                ans[i] = ans[i]==1?2:1;
               else{
                ans[i] = ans[i]==1?2:1;
                break;
               }
           }

       }
       cout<<ansm<<endl;
       for(auto i =0;i<n;i++)
        cout<<ans[i]<<" ";
}
int main()
{
    ll t=1;
    cin>>t;
    while(t--)
    {
     solve();
     cout<<endl;
    }
	return 0;
}
