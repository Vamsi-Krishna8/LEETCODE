class Solution {
public:
    int n;
    int dp[501];

    int solve(int idx,vector<int> &arr,int k){
        if(idx>n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int curr_max=-1;
        int res=0;
        for(int j=idx;j<n && (j-idx+1)<=k;j++){
            curr_max=max(curr_max,arr[j]);
            res=max(res,(j-idx+1)*curr_max+solve(j+1,arr,k));
        }
        return dp[idx]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,arr,k);
    }
};

// TABULATION
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int curr_max=-1;
            for(int j=1;j<=k && i+j<=n;j++){
                curr_max=max(curr_max,arr[i+j-1]);
                dp[i]=max(dp[i],curr_max*(j)+dp[i+j]);
            }
        }
        return dp[0];
    }
};