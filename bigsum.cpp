#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <ll> v;
int n;
ll dp[10007];
ll call(int i){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    return dp[i]=max(v[i]+call(i+2),call(i+1));
}
int main(){
    int t;
    cin>>t;
    for(int j=1; j<=t; j++){

        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0; i<n; i++){
            ll x;
            scanf("%lld",&x);
            v.push_back(x);
        }
        printf("Case %d: %lld\n",j,call(0));
        v.clear();
    }
}
/// 10 20 2 1 30 1
