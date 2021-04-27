#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
string s="ppppaqppp",s1="pppqapppp";
void printsol(int i, int j){
    if(i<0 || j<0)return ;
    if(dp[i][j]>dp[i-1][j-1]){
        cout<<s[j-1];
        printsol(i-1,j-1);
    }
    else if(dp[i][j]==dp[i][j-1])printsol(i,j-1);
    else printsol(i-1,j);

}
int main(){

    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }
            else if(s1[i-1]==s[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    printsol(9,9);
}
