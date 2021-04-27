#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int siz=3, coin[] = {1, 2 , 5} , limit[] = {3,2,1};

int call(int i , int n){
    if(i>=siz){
        if(n==0)return 1;
        return 0;
    }
    int &v = dp[i][n];
    if(v!=-1)return v;
    v=0;
    for(int j=0; j<=limit[i] && n-(j*coin[i])>=0; j++){
        v =  v%100000007 + call(i+1,n-(j*coin[i]))%100000007;
    }
    return v;

}

int main(){
    int w;
    while(1){
        memset(dp,-1,sizeof(dp));
        cin>>w;
        cout<<call(0,w)<<endl;;
    }
    return 0;
}
