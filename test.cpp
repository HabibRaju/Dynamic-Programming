#include <bits/stdc++.h>
using namespace std;
string s;
int dp[100][100];
int call(int i, int j){
    if(i>=j){
        if(i==j){
            if(s[i]==s[j])return 1;
            return 0;
        }
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s[j])return dp[i][j] = 2+call(i+1,j-1);
    return dp[i][j] = max(call(i+1,j),call(i,j-1));
}
int main(){
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<call(0,s.size()-1);
}
