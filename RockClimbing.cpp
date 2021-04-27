#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int a[MAX][MAX];
int dp[MAX][MAX];
int row,col;

bool valid(int i, int j){
    if(i>=0 && i<row && j>=0 && j<col)return true;
    return false;
}

int call(int i, int j){
    if(!valid(i,j))return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int res = INT_MIN;
    res = max(res,call(i+1,j)+a[i][j]);
    res = max(res,call(i+1,j+1)+a[i][j]);
    res = max(res,call(i+1,j+1)+a[i][j]);
    return dp[i][j] = res;

}

int main(){
    cin>>row>>col;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<call(0,0);
}

/**
3 3

-1 2 5
4 -2 3
1 2 10

ans = 7
*/

///*******************************************************
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int a[MAX][MAX];
int dp[MAX][MAX];
int row,col;

bool valid(int i, int j){
    if(i>=0 && i<row && j>=0 && j<col)return true;
    return false;
}

int call(int i, int j){
    if(!valid(i,j))return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int res = INT_MIN;
    res = max(res,call(i+1,j-1)+a[i][j]);
    res = max(res,call(i+1,j+1)+a[i][j]);
    return dp[i][j] = res;

}

int main(){
    cin>>row>>col;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<call(0,col/2);
}


/**
5 5

-10000000 -10000000 7 -10000000 -10000000
-10000000 5 -10000000 2 -10000000
-3 -10000000 -4 -10000000 -2
-10000000 -1 -10000000 -5 -10000000
-10000000 -10000000 7 -10000000 -10000000

ans = 15;
*/
