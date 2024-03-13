class Solution {
public:
    int dp[10001];
    int help(int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int minCount=INT_MAX;
        for(int i=1;i*i<=n;i++){
            minCount=min(minCount,1+help(n-i*i));
        }
        return dp[n]=minCount;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return help(n);
    }
};