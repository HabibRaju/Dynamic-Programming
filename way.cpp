#include <bits/stdc++.h>
using namespace std;
int n;
char arr[50][50];
int dp[100][100];
int call(int i, int j){
    if(i>=n || j>=n)return 0;
    if(i==n-1 && j==n-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];

    int x = 0;
    if(arr[i+1][j]=='.'){
        x+= call(i+1,j);
    }
    if(arr[i][j+1]=='.'){
        x+= call(i,j+1);
    }
    return dp[i][j] = x;

}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<call(0,0);

}
