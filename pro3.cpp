#include <bits/stdc++.h>
using namespace std;
/// max sub array  A[i1] - A[i2] +A[i3]....a[in]
int arr[] = {3,1,-1,100,2},n=5;
int dp[1000][2];

int call(int idx,bool pre){
    if(idx>=n)return 0;

    if(dp[idx][pre]!=-1)return dp[idx][pre];

    int val1,val2;

    if(pre==true)val1 = (call(idx+1,false))+arr[idx];
    else val1 = call(idx+1,true)-arr[idx];

    val2 = call(idx+1,pre);

    return dp[idx][pre] = max(val1,val2);
}

int main(){
    memset(dp,-1,sizeof(dp));
    cout<<call(0,1)<<endl;


}

