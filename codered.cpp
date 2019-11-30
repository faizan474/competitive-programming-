#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define fr(i,l,r) for(int i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define  mp(x,y) make_pair(x,y)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
const ll v=1002;
ll  arr[v][v];
ll preA[v][v]; 
void printPascal() 
{  
   for (int line = 0; line <1001; line++) 
    { 
      for (int i = 0; i <= line; i++) 
        { 
      if (line == i || i == 0) 
           { arr[line][i] = 1;
           if(i==0)
           preA[line][i]=1;
           else  if(i==line)
           preA[line][i]=preA[line][i-1]+arr[line][i];
           } 
     else
            arr[line][i] = (arr[line - 1][i - 1] +  
                            arr[line - 1][i])%mod; 
                            preA[line][i]=(preA[line][i-1]+arr[line][i])%mod;
   //  cout << arr[line][i] << "$$"; 
    // cout<<preA[line][i]<<" ";
        } 
       // cout << "\n"; 
    }
} 
long long int power(long long int x, unsigned long long int y)
{
	long long int res = 1;	

	x = x %mod; 

	while (y > 0)
	{
	if (y & 1)
			res = (res*x) %mod;

		
		y = y>>1;
		x = (x*x) % mod;
	}
	return res;
}
long long moduloMultiplication(long long a,
                            long long b)
{
    long long res = 0; 

    a %= mod;

    while (b)
    {
      
        if (b & 1)
            res = (res + a) % mod;

        a = (2 * a) % mod;

        b >>= 1; 
    }

    return res;
}

void solve(){
    ll A,B,C;
    cin>>A>>B>>C;
    ll ab=0;
    ll c=power(2,C)-1;
    //cout<<"C"<<c<<endl;
    for(ll i=1;i<=B;i++){
        if(i>A)
        break;
       // cout<<i<<" "<<endl;
     //cout<<arr[B][i]<<" "<<(mod+preA[A][A]-preA[A][i])%mod<<endl;
    ab+=moduloMultiplication((arr[B][i]),(preA[A][A]-preA[A][i]+mod)%mod);
    ab%=mod;
  //cout<<ab<<"----<";
    }
   ll  ans=moduloMultiplication(c,ab);
    cout<<ans<<endl;
    
}

int main(){
    
printPascal();
 //clog<<((long double)(clock()-launch)/CLOCKS_PER_SEC)<<"\n";
ll t;
cin>>t;
while(t--){
    clock_t launch=clock();
    solve();
   clog<<((long double)(clock()-launch)/CLOCKS_PER_SEC)<<"\n";
}

}









