#include <bits/stdc++.h>
using namespace std;
int dp[1000];

int call(int n){
    if(n==1 || n==2)return n;
    if(dp[n]!=-1)return dp[n];

    return dp[n] = call(n-1)+call(n-2);

}

int main(){
    memset(dp,-1,sizeof(dp));
    cout<<call(4);

}
