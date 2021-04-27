#include <bits/stdc++.h>
using namespace std;
#define MAX_N 20
#define MAX_W 10000
#define INF 99999999
#define EMPTY_VALUE -1

int n = 5, coin[]={2, 5, 9, 10, 15};
int dp[100][100];

int call(int idx , int amount){
    if(amount<0)return INF;

    if(n==idx){
        if(amount==0)return 0;
        return INF;
    }
    if(dp[idx][amount]!=-1)return dp[idx][amount];

    int res1 = 1 + call(idx+1,amount-coin[idx]);
    int res2 = call(idx+1,amount);

    return dp[idx][amount] = min(res1,res2);
}

int main(){
    while(true){
        memset(dp,-1,sizeof(dp));
        int w;
        cin>>w;
        cout<<call(0,w)<<endl;
    }
}


/**
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 20
#define MAX_W 10000
#define INF 99999999
#define EMPTY_VALUE -1
int C[] = {2, 5, 9, 13, 15};
int mem[MAX_N][MAX_W];
int n=5;
int f(int i, int W){
    if (W < 0)
        return INF;
    if (i == n){
        if (W == 0)
            return 0;
        return INF;
    }
    if (mem[i][W] != EMPTY_VALUE){
        return mem[i][W];
    }
    int res_1 = 1 + f(i, W - C[i]); //only this line updated
    int res_2 = f(i + 1, W);
    mem[i][W] = min(res_1, res_2);
    return mem[i][W];
}

int main(){
    while(true){
        memset(mem,-1,sizeof(mem));
        int w;
        cin>>w;
        cout<<f(0,w)<<endl;
    }
}
*/
