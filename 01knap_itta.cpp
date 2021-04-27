#include <bits/stdc++.h>
using namespace std;

struct node{
    int w,v;

};

int dp[100][100];
node arr[100];

void PrintItem(int Ti,int Tw){
    if(Ti<0 || Tw<0)return;
    if(dp[Ti][Tw] == dp[Ti-1][Tw])PrintItem(Ti-1,Tw);
    else {
        cout<<arr[Ti].w<<" "<<arr[Ti].v<<endl;
        PrintItem(Ti-1,Tw-arr[Ti].w);
    }

}
int main(){
    int Ti,Tw;cin>>Ti>>Tw;
    for(int i=1; i<=Ti; i++){
        int w,v;cin>>w>>v;
        arr[i].w=w;
        arr[i].v=v;
    }

    for(int i=0; i<=Ti; i++){
        for(int j=0; j<=Tw; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }
            if(j<arr[i].w){
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(arr[i].v+dp[i-1][j-arr[i].w],dp[i-1][j]);
            }
        }
    }
    for(int i=0; i<=Ti; i++){
        for(int j=0; j<=Tw; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    PrintItem(Ti,Tw);
}




/**

4 7
1 1
3 4
4 5
5 7

0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1
0 1 1 4 5 5 5 5
0 1 1 4 5 6 6 9
0 1 1 4 5 7 8 9

*/


