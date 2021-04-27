#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
int dp[100][100];
int nCr(int n,int r){
    if(r==1)return dp[n][r]=n;
    if(r==n)return dp[n][r]=1;
    if(dp[n][r]!=-1)return dp[n][r];
    return dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;
//    for(int i=r; i<=n; i++){
//        for(int j=1; j<=r; j++){
//            cout<<i<<" "<<j<<"  "<<dp[i][j]<<endl;
//        }
//        cout<<endl;
//    }
}

