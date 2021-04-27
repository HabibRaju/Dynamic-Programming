#include <bits/stdc++.h>
using namespace std;
#define MAX_N 20
#define MAX_W 10000
#define INF 99999999
#define EMPTY_VALUE -1

int n = 5, coin[]={2, 5, 9, 11, 15};
int dp[100][100];

int call(int idx , int amount){
    if(amount<0)return INF;

    if(n==idx){
        if(amount==0)return 0;
        return INF;
    }
    if(dp[idx][amount]!=-1)return dp[idx][amount];

    int res1 = 1 + call(idx,amount-coin[idx]);
    int res2 = call(idx+1,amount);

    return dp[idx][amount] = min(res1,res2);
}

int main(){
    memset(dp,-1,sizeof(dp));
    cout<<call(0,22)<<endl;
}
