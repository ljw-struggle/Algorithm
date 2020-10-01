#dynamic programming is the most important and usefull concept , this algorithm plays a very important role in coding interviews


#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

char a[1001], b[1001];
int dp[1001][1001] = {0}, len_a, len_b;

int lcs_continuous(int len_a, int len_b){
    //it will return the maximum length of an subarray that appears in both arrays. (continuous)
    int ans=0;
    for(int i=1;i<=len_a;i++){
        for(int j=1;j<=len_b;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
            
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
} 

int lcs_incontinuous(int len_a, int len_b){
    // return the maximum length of an subarray that appears in both arrays. (incontinuous)
    for(int i=1;i<=len_a;i++){
        for(int j=1;j<=len_b;j++){
            if(a[i-1]=b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }	
    return dp[len_a][len_b];
}

int main(){
    while(~scanf("%s", a)){
        scanf("%s", b);
        len_a = strlen(a);
        len_b = strlen(b);
        memset(dp, 0, sizeof(dp));
        int res_continuous = lcs_continuous(len_a, len_b);
        int res_incontinuous = lcs_incontinuous(len_a, len_b);
        printf("%d %d\n", res_continuous, res_incontinuous);
    }
    return 0;
}
