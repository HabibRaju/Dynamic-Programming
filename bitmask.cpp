#include <bits/stdc++.h>
using namespace std;

int n=3;
bool chk(int mask){
    return (bool)(mask & ((1<<10)-1));
}

int dp[1000][(1<<10)+2];

int fun(int pos,int mask){

    if(pos>=n){
        if(chk(mask))return 1;
        return 0;
        }
    if(dp[pos][mask]!=-1)return dp[pos][mask];

    int low=0,res=0;
    if(pos==0)low=1;
    for(int i=low; i<10; i++){
        int val = fun(pos+1, mask | (1<<pos));
        res+=val;
    }
    return dp[pos][mask] = res;

}

int main(){
    memset(dp,-1,sizeof(dp));
    cout<<fun(0,0);
}
