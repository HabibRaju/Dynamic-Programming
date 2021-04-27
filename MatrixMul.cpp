#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
struct Matrix{
	int row,col;
};

Matrix mats[100];int n;

int margeCost(int i, int j, int k){
    cout<<"test"<<endl;
	return mats[i].row*mats[k].col*mats[j].col;
}

int solve(int i, int j){
	if(i==j)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int ans = INT_MAX;
	for(int k=i; k<j; k++){
		int Call_Left = solve(i,k);
		int Call_Right = solve(k+1,j);
		int cost = (Call_Right+Call_Left)+margeCost(i,j,k);
		ans = min(ans,cost);
	}
	return dp[i][j] =ans;
}

int main(){

    cin>>n;
    for(int i=0; i<n; i++){
    	cin>>mats[i].row>>mats[i].col;
    }
    memset(dp,-1,sizeof(dp));

    cout<<solve(0,n-1)<<endl;

}
