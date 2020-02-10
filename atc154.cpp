/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int a, b, d, k;
int DP[101][4][2];
//DP[pos][cnt][f];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than  nb? [0 =no, 1 = yes]

int call(int pos, int cnt, int f){
    if(cnt > k) return 0;

    if(pos == num.size()){
        if(cnt == k) return 1;
        return 0;
    }

    if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    int res = 0;

    int LMT;

    if(f == 0){
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        if(dgt != 0) ncnt++;      // given condition brother
        if(ncnt <= k) res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

int solve(string &b){
    num.resize(b.size());
    for(int i=0;i<b.size();i++){
    num[i]=b[i]-'0';
    //cout<<num[i]<<" ";
    }
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    return res;
}

int main () {

     string str;
     cin>>str;
     
     cin>>k;
    cout<<solve(str);

    return 0;
}