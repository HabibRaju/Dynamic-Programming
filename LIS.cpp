#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int siz,arr[MAX];
int dp[MAX];
int index[MAX];

int call(int i){
    if(dp[i]!=-1)return dp[i];
    int ans =0;

    for(int j=i+1; j<siz; j++){
        if(arr[j]>arr[i]) {
            int res =  call(j);
            if(res>ans){
                ans = res;
                index[i] = j;
            }
        }
    }
    return dp[i] = ans+1;
}

void pathPrint(int idx){
    while(idx!=-1){
        cout<<arr[idx]<<" ";
        idx = index[idx];
    }
}

int main(){
    cin>>siz;
    for(int i=0; i<siz; i++)cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    memset(index,-1,sizeof(index));
    int ans =0,idx=-1;
    for(int i=0; i<siz; i++){
        int res = call(i);
        if(res>ans){
            ans = res;
            idx=i;
        }
    }
    cout<<ans<<endl;
    pathPrint(idx);

}



/**
7
5 0 9 2 7 3 4

ans = 4
*/
