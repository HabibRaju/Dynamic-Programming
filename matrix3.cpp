#include <bits/stdc++.h>
using namespace std;
int dp[1000];

int call(int n){
    if(n==1)return 1;
    if(n==2)return 2;
    if(n==3)return 6;
    if(dp[n]!=-1)return dp[n];

    return dp[n] = call(n-1)+call(n-2)+call(n-2);

}

int main(){
    memset(dp,-1,sizeof(dp));
    cout<<call(4);

}

