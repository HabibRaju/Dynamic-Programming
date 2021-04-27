#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
int dp[100][100];
vector <int> coin;
int totalCoin,make;

int call(int idx , int w){
    if(idx>=totalCoin){
        if(w==0)return 1;
        else return 0;
    }

    if(dp[idx][w]!=-1)return dp[idx][w];
    int res1=0,res2=0;
    if(w-coin[idx]>=0){
        res1 = call(idx,w-coin[idx]);
    }
    res2 = call(idx+1,w);

    return dp[idx][w] = res1 + res2;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>totalCoin>>make;
    for(int i=0; i<totalCoin; i++){
        int x;
        cin>>x;
        coin.push_back(x);
    }
    int x = call(0,make);
    if(x)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<x<<endl;
}

/**
5 7
2 3 4 5 7
ans = 4
*/












