#include <bits/stdc++.h>
using namespace std;
///por3 er same but pasapari neya jabe na
int arr[] = {3,-100,2,-5,10},n=5;
int dp[1000][3];

int call(int idx, bool flag){
    if(idx>=n)return 0;
    if(dp[idx][flag]!=-1)return dp[idx][flag];

    int val1,val2;
    if(flag==true){
        val1 = call(idx+2,false)+arr[idx];
    }
    else val1 = call(idx+2,true)-arr[idx];
    val2 = call(idx+1,flag);

    return dp[idx][flag] = max(val1,val2);


}
int main(){

    memset(dp,-1,sizeof(dp));
    cout<<call(0,1);
}
