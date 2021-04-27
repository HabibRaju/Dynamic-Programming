#include <bits/stdc++.h>
using namespace std;

string s="tanvir",s1="tanzil";
int dp[100][100];
int ansi=0,ansj=0,ans=-1;
int main(){
    for(int i=0; i<=5; i++){
        for(int j=0; j<=6; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }
            else if(s[i-1]==s1[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                if(ans<dp[i][j]){
                    ans = dp[i][j];
                    ansi=i,ansj=j;
                }
            }
        }
    }

    for(int i=0; i<=6; i++){
        for(int j=0; j<=6; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<=5; i++){
        for(int j=0; j<=6; j++){
           if(dp[i][j]>dp[i-1][j-1] && i!=0 && j!=0)cout<<s[i-1];
        }
    }
    cout<<endl<<dp[ansi][ansj]<<endl;
}
