#include <bits/stdc++.h>
using namespace std;

string s,s1;

int intConvert(string s){
    int n;
    stringstream geek(s);
    geek >> n;
    return n;
}

string strConvert(int n){
    string s;
    stringstream ss;
    ss << n;
    s=ss.str();
    return s;
}


int dp[12][2][99][99][2];
int x;

int fun(int pos,int isSmall,int digitsum,int sum,bool flag){
    if(flag==false){
        if(pos>=s.size()){
            if(digitsum%x==0 && sum%x==0 && digitsum>0){
                ///cout<<digitsum<<" "<<sum<<endl;
                return 1;
            }
            return 0;
        }

        if(dp[pos][isSmall][digitsum][sum][flag]!=-1)return dp[pos][isSmall][digitsum][sum][flag];

        int lo=0,hi=s[pos]-'0',res=0;
        if(isSmall)hi=9;

        for(int i=0; i<=hi; i++){
            int newSmall = isSmall | (i<hi);

            int val = fun(pos+1,newSmall,digitsum+i,((sum*10)+i)%x,flag);
            res+=val;
        }
        return dp[pos][isSmall][digitsum][sum][flag] = res;
    }


    else {
        if(pos>=s1.size()){
            if(digitsum%x==0 && sum%x==0 && digitsum>0){
                ///cout<<digitsum<<" "<<sum<<endl;
                return 1;
            }
            return 0;
        }

        if(dp[pos][isSmall][digitsum][sum][flag]!=-1)return dp[pos][isSmall][digitsum][sum][flag];

        int lo=0,hi=s1[pos]-'0',res=0;
        if(isSmall)hi=9;

        for(int i=0; i<=hi; i++){
            int newSmall = isSmall | (i<hi);

            int val = fun(pos+1,newSmall,digitsum+i,((sum*10)+i)%x,flag);
            res+=val;
        }
        return dp[pos][isSmall][digitsum][sum][flag] = res;

    }

}

int main(){
    int t;cin>>t;
    for(int cas=1; cas<=t; cas++){
        cin>>s1>>s>>x;
        memset(dp,-1,sizeof(dp));
        if(x>82)cout<<"Case "<<cas<<": 0"<<endl;
        else {
            int ans1 = fun(0,0,0,0,0);
            memset(dp,-1,sizeof(dp));
            int k  = intConvert(s1);
            s1 = strConvert(k-1);
            int ans2 = fun(0,0,0,0,1);
            cout<<"Case "<<cas<<": "<<ans1-ans2<<endl;
        }
    }
}
