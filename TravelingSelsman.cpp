#include <bits/stdc++.h>
#define inf 100000007
using namespace std;

int arr[10][10];int n;

int dp[10][1<<10];


int main(){
    cin>>n;
    for(int i=0; i<=500; i++){
        for(int j=0; j<=500; j++){
            arr[i][j]=inf;
        }
    }
    for(int i=0; i<n; i++){
        int u,v,w;
        cin>>u>>v>>w;
        arr[u][v]=w;
        arr[v][u]=w;
    }



}
