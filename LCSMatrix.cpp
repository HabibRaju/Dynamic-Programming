#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];
int main(){
    string s1,s2,ans="",ans1="";
    cin>>s1>>s2;
    int len1=s1.size();
    int len2 = s2.size();

    for(int i=0; i<=len1; i++){
        a[0][i]=0;
    }

    for(int i=0; i<len2; i++){
        a[i][0];
    }

    for(int i=1; i<=len2+1; i++){
        for(int j=1; j<=len1+1; j++){
            if(s1[i-1]==s2[j-1]){

                a[i][j]=1+a[i-1][j-1];
            }
            else {

                a[i][j]=max(a[i][j-1],a[i-1][j]);
            }
        }
    }
    cout<<endl<<endl;
    for(int i=0; i<len2+1; i++){
        for(int j=0; j<len1+1; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int m=a[len1][len2];

    int len = s1.size();
    int ses=s2.size();

    for(int i=0; i<len; i++){
        int cnt=1;
        int j=0;
        if(m==0)break;

        while(cnt){
            if(s1[i]==s2[j]){
                ans+=s1[i];
                m--;
                cnt--;
            }
            if(j==ses-1 && cnt)cnt--;
            ++j;
        }
    }
    cout<<ans<<endl;
}
