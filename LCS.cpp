#include <bits/stdc++.h>
using namespace std;

int dp[1007][1007];
string s1,s2;
int len1,len2;

int call(int i, int j){

    if(i>=len1 || j>=len2)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int ret=0;
    if(s1[i]==s2[j]){
        ret+=1+call(i+1,j+1);

    }
    else {
        int a=call(i,j+1);
        int b=call(i+1,j);
        ret=max(a,b);
    }
    return dp[i][j]=ret;
}

int main(){



    while(getline(cin,s1)){
         getline(cin,s2);
         memset(dp,-1,sizeof(dp));
        len1=s1.size();
        len2=s2.size();
        cout<<call(0,0)<<endl;;
    }

    return 0;
}
