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
   int dp[301][27][27];
      unordered_map<char,pair<int,int>>m;
    int find(string &s,int idx,char h1,char h2){
        if(idx==s.size())
            return 0;
        int &res=dp[idx][h1-'A'][h2-'A'];
        if(res!=-1)
            return res;
        if(h1==s[idx]){
            return find(s,idx+1,s[idx],h2);
        }
        else if(h2==s[idx]){
            return find(s,idx+1,h1,s[idx]);
        }
        
        int dis1=h1=='['?0:(abs(m[h1].first-m[s[idx]].first)+abs(m[h1].second-m[s[idx]].second));
        int dis2=h2=='['?0:(abs(m[h2].first-m[s[idx]].first)+abs(m[h2].second-m[s[idx]].second));
        res=min(find(s,idx+1,s[idx],h2)+dis1,find(s,idx+1,h1,s[idx])+dis2);
        return res;
    }
    int minimumDistance(string word) {
        int n=word.size();
        if(n==0)
            return 0;
      
        char ch='A';

        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                
                m[ch]={i,j};
                ch++;
                if(ch>'Z')
                    break;
                
                
            }
        }
        memset(dp,-1,sizeof(dp));
         // for(auto it=m.begin();it!=m.end();it++)
          //    cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
       return find(word,0,'[','[');
        return 0;
        
    }
void solve(){

  string str;
  cin>>str;
  cout<<minimumDistance(str);
  
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
