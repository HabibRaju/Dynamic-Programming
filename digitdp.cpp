#include <bits/stdc++.h>
using namespace std;

string s="50";



int dp[12][2][99][99];
int x=3;

int fun(int pos,int isSmall,int digitsum,int sum){

        if(pos>=s.size()){
            if(digitsum%x==0 && sum%x==0 && digitsum>0){

                return 1;
            }
            return 0;
        }

        if(dp[pos][isSmall][digitsum][sum]!=-1)return dp[pos][isSmall][digitsum][sum];

        int lo=0,hi=s[pos]-'0',res=0;
        if(isSmall)hi=9;

        for(int i=0; i<=hi; i++){
            int newSmall = isSmall | (i<hi);

            int val = fun(pos+1,newSmall,digitsum+i,((sum*10)+i)%x);
            res+=val;
        }
        return dp[pos][isSmall][digitsum][sum] = res;
}




int main(){
   memset(dp,-1,sizeof(dp));
  cout<<fun(0,0,0,0)<<endl;
}
