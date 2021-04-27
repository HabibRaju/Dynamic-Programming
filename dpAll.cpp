/// Coin Change with each coin's limit
#include <bits/stdc++.h>
using namespace std;

int coin[]={3,6,9,7}, siz=4;
int limit[]={3,2,5,2};
int dp[5][1000];

/// returns the number of ways n can be created
int coinChange(int i, int n){
    if(i>=siz){
        if(n==0)
            return 1;
        return 0;
    }
    int &v = dp[i][n];
    if(v!=-1) return v;
    v=0;
    for(int j=0; j<=limit[i] && n-(j*coin[i])>=0; j++){
        v += coinChange(i+1,n-(j*coin[i]));
    }
    return v;
}

int main(){

    memset(dp,-1,sizeof(dp));
    int n;
    while(cin>>n){
        cout << coinChange(0,n) << endl;
    }

    return 0;
}



#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <int> digit;
ll dp[20][2][2][50], len;

void makeDigit(ll n){
    while(n!=0){
        digit.push_back(n%10);
        n/=10;
    }
    reverse(digit.begin(),digit.end());
}

ll call(int pos, bool isSmall, bool isStart, ll value){
    if(pos==len) return value;
    if(dp[pos][isSmall][isStart][value]!=-1) return dp[pos][isSmall][isStart][value];

    int ses=isSmall? 9: digit[pos];
    ll ret=0;

    if(!isStart){
        for(int i=0; i<=ses; i++){
            ret+=call(pos+1, isSmall | i<digit[pos], 0, value+ (int)(i==0));
        }
    }
    else{
        ret+=call(pos+1,1,1,0);
        for(int i=1; i<=ses; i++){
            ret+=call(pos+1, isSmall | i<digit[pos], 0, value);
        }
    }

    return dp[pos][isSmall][isStart][value]=ret;
}

ll cal(ll n){
    if(n<0) return 0;
    if(n<=9) return 1;
    digit.clear(); makeDigit(n); len=digit.size();
    memset(dp,-1,sizeof dp);
    return call(0,0,1,0)+1;
}

int main(){
    ll t;
    cin>>t;

    for(int i=1; i<=t; i++){
        ll m,n;
        cin>>m>>n;
        cout<<"Case "<<i<<": "<<cal(n)-cal(m-1)<<endl;
    }
    return 0;
}



/// Digit-DP
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <int> digit;
ll dp[20][2][1000], lim;

void makeDigit(ll n){
    while(n!=0){
        digit.push_back(n%10);
        n/=10;
    }
    reverse(digit.begin(),digit.end());
}

ll call(int pos, bool isSmall, ll sum){
    if(pos>=lim) return sum;
    ll &v=dp[pos][isSmall][sum];

    if(v!=-1) return v;

    ll ret=0;
    int ses=isSmall? 9: digit[pos];

    for(int i=0; i<=ses; i++){
        ret+=call(pos+1, isSmall | i<digit[pos], sum+i);
    }
    return v=ret;
}

ll cal(ll n){
    if(n<=0) return 0;
    digit.clear(); makeDigit(n); lim=digit.size();
    memset(dp,-1,sizeof dp);
    return call(0,0,0);
}

int main(){
    cout<<cal(9)<<endl;
    cout<<cal(10)<<endl;
    cout<<cal(11)<<endl;
    cout<<cal(12)<<endl;
    cout<<cal(13)<<endl;
    cout<<cal(14)<<endl;
    cout<<cal(15)<<endl;
    return 0;
}



#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <int> digit;
ll k;
ll dp[20][20][50][2], len;

void makeDigit(ll n){
    while(n!=0){
        digit.push_back(n%10);
        n/=10;
    }
    reverse(digit.begin(),digit.end());
}

ll call(int pos, int rem, int remdigit, bool isSmall){
    if(pos==len) return !(rem+remdigit);
    if(dp[pos][rem][remdigit][isSmall]!=-1) return dp[pos][rem][remdigit][isSmall];

    int ses=isSmall? 9: digit[pos];
    ll ret=0;

    for(int i=0; i<=ses; i++){
        ret+=call(pos+1, (rem*10+i)%k, (remdigit+i)%k, isSmall | i<digit[pos]);
    }

    return dp[pos][rem][remdigit][isSmall]=ret;
}

ll cal(ll n){
    if(n<0) return 0;
//    if(n<=9) return 1;
    digit.clear(); makeDigit(n); len=digit.size();
    memset(dp,-1,sizeof dp);
    return call(0,0,0,0);
}

int main(){
    ll t;
    cin>>t;

    for(int i=1; i<=t; i++){
        ll m,n;
        cin>>m>>n>>k;

        if(m>n) swap(m,n);
        if(k==1) cout<<"Case "<<i<<": "<<(n-m)+1<<endl;
        else if(k>99) cout<<"Case "<<i<<": "<<0<<endl;
        else cout<<"Case "<<i<<": "<<cal(n)-cal(m-1)<<endl;
    }
    return 0;
}



/// 0-1 Knapsack DP
#include <bits/stdc++.h>
using namespace std;

struct ITEM{
    int weight, price;
};

ITEM item[100];
int n, capacity, dp[100][100];

int call(int idx, int weight){
    if(idx>=n)
        return 0;
    if(dp[idx][weight]!=-1) return dp[idx][weight];
    if(weight-item[idx].weight>=0)
        return dp[idx][weight] = max(item[idx].price+call(idx+1,weight-item[idx].weight),call(idx+1,weight));
    else
        return dp[idx][weight] = call(idx+1,weight);
}

int main(){

    cin >> n >> capacity;
    for(int i=0; i<n; i++){
        cin>>item[i].weight>>item[i].price;
    }
    memset(dp,-1,sizeof dp);
    cout << call(0,capacity) << endl;

    return 0;
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



/// LCS (Longest Common Subsequence)
#include <bits/stdc++.h>
using namespace std;
#define mx 507

string s1,s2;
int len1, len2;
int dp[mx][mx];

int lcs(int i, int j){ /// Longest Common Subsequence
    if(i==len1 || j==len2) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(s1[i]==s2[j])
        ans=1+lcs(i+1,j+1);
    else
        ans=max(lcs(i+1,j),lcs(i,j+1));
    dp[i][j]=ans;
    return ans;
}

void printlcs(int i, int j){ /// print any one of the solutions when many solutions available
    if(i==len1 || j==len2) return;
    if(s1[i]==s2[j]){
        printf("%c",s1[i]);
        printlcs(i+1,j+1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1])
            printlcs(i+1,j);
        else
            printlcs(i,j+1);
    }
}

string ans;
void printlcs2(int i, int j){ /// print all the possible solutions
    if(i==len1 || j==len2){
        cout << ans << endl; /// you may also strore the answers
        return;
    }
    if(s1[i]==s2[j]){
        ans+=s1[i];
        printlcs2(i+1,j+1);
        ans.erase(ans.end()-1); /// delete last character
    }
    else{
        if(dp[i+1][j]>dp[i][j+1])
            printlcs2(i+1,j);
        else if(dp[i][j+1]>dp[i+1][j])
            printlcs2(i,j+1);
        else{ /** if dp i+1,j equals to dp i,j+1, then many solutions available
                we'll go try both way in this case */
            printlcs2(i+1,j);
            printlcs2(i,j+1);
        }
    }
}

int main(){

    memset(dp,-1,sizeof(dp)); /// initializing the dp array with -1
    cin >> s1 >> s2;
    len1=s1.size(), len2=s2.size();
    cout << lcs(0,0) << endl;
    printlcs2(0,0);

    return 0;
}



/// RockClimbing DP
#include <bits/stdc++.h>
#define max3(a,b,c) max(a,max(b,c))
using namespace std;

int grid[100][100], r,c , dp[100][100];

void init(){
    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>grid[i][j];
    memset(dp,-1,sizeof dp);
}

bool valid(int i, int j){
    if(i>=0 && i<r && j>=0 && j<c)
        return 1;
    return 0;
}

int call(int i, int j){
    if(!valid(i,j))
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] + max3(call(i+1,j-1),call(i+1,j),call(i+1,j+1));
}

int main(){

    init();
    int ans=0;
    for(int col=0; col<c; col++)
        ans=max(ans,call(0,col));
    cout << ans << endl;

    return 0;
}

/** test case:
3 3
2 4 7
4 -5 -2
1 5 4
ans:13
*/
