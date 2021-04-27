
#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
int dp[100][100];
vector<ii>Item;
int totalItem,totalCapacity;

int call(int idx,int weight){
    if(idx>=totalItem)
        return 0;
    if(dp[idx][weight]!=-1) return dp[idx][weight];

    if(weight-Item[idx].first>=0)

        return dp[idx][weight] = max(Item[idx].second+call(idx+1,weight-Item[idx].first),call(idx+1,weight));

    else return dp[idx][weight] = call(idx+1,weight);

}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>totalItem>>totalCapacity;
    for(int i=0; i<totalItem; i++){
        int weight,cost;
        cin>>weight>>cost;
        Item.push_back(ii(weight,cost));
    }
    cout<<call(0,totalCapacity)<<endl;
}


/** test case:
5 10
1 120
7 400
4 280
3 150
4 200
ans: 600
*/
