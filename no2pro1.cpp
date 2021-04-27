#include <bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<int,ii>
using namespace std;
int n;
vector <iii> v;
vector <int> v1;
int dp[1000];

int call(int idx){
    if(idx>=n)return 0;
    if(dp[idx]!=-1)return dp[idx];

    int val1,val2;
    if(v[idx].second.first>v1[n-1]){
        val1 = v[idx].second.second + call(n+1);
    }
    else {
        auto it = upper_bound(v1.begin(),v1.end(),v[idx].second.first);
        int x = distance(v1.begin(),it);
        val1 = v[idx].second.second + call(x);
    }
    val2 = call(idx+1);

    return dp[idx] = max(val1,val2);

}
int main(){

    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0; i<n; i++){
        int s,e,m;cin>>s>>e>>m;
        v.push_back(iii(s,ii(e,m)));
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        v1.push_back(v[i].first);
    }
    cout<<call(0)<<endl;
}


/**
5

1 5 10
4 12 20
13 15 8
7 14 15
8 10 11


ans = 29

*/


