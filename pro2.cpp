#include <bits/stdc++.h>
using namespace std;

int arr[] = {3,1,-100,100},n=4;

/// max sub array  1*A[i1] + 2*A[i2] ....n*a[in]
int dp[1000][1000];

int call(int idx,int pre){
    if(idx>=n)return 0;

    if(dp[idx][pre]!=-1)return dp[idx][pre];

    return  dp[idx][pre] = max(call(idx+1,pre+1)+(arr[idx]*pre),call(idx+1,pre));


}

int main(){
    memset(dp,-1,sizeof(dp));
    cout<<call(0,1)<<endl;


}
