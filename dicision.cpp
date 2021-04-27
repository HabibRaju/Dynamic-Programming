#include <bits/stdc++.h>
using namespace std;
char grid[10][10];
bool vis[10][10];
int n,m;
int dp[100][100];

int solution(int i, int j){
    if(i>=n && j>=m)return 0;
    if(i==n-1 && j==m-1){
       // vis[i][j]=true;
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    int res1=0,res2=0,res3=0;
    if(grid[i+1][j]=='.' ){
        //vis[i+1][j]=false;
        res1=solution(i+1,j);
    }
    if(grid[i+1][j+1]=='.' ){
        //vis[i+1][j+1]=false;
        res2=solution(i+1,j+1);
    }
    if(grid[i][j+1]=='.' ){
        ///vis[i][j+1]=false;
        res3=solution(i,j+1);
    }

    return dp[i][j] = res1+res2+res3;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            vis[i][j] = true;
        }
    }

    cout<<solution(0,0)<<endl;
}


