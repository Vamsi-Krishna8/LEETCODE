//RECURSION

class Solution {
public:

    void help(int idx,vector<int> &nums,vector<int> &result,vector<int> &temp,int prev_idx){
        if(idx>=nums.size()){
            if(temp.size()>result.size()){
                result=temp;
            }
            return;
        }
        //take
        if(prev_idx==-1 || nums[idx]%prev_idx==0){
            temp.push_back(nums[idx]);
            help(idx+1,nums,result,temp,nums[idx]);
            temp.pop_back();
        }
        //not take
        help(idx+1,nums,result,temp,prev_idx);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> temp;
        vector<int> res;
        int prev_idx=-1;
        help(0,nums,res,temp,prev_idx);
        return res;
    }
};

// TABULATION

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        vector<int> prev_idx(n,-1);
        int max_len=1;
        int last_idx=-1;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[j]%nums[i]==0){
                    if(dp[j]<dp[i]+1){
                        dp[j]=dp[i]+1;
                        prev_idx[j]=i;
                    }
                    if(dp[j]>max_len){
                        max_len=dp[j];
                        last_idx=j;
                    }
                }
            }
        }
        vector<int> res(max_len,0);
        int idx=max_len-1;
        while(last_idx!=-1){
            res[idx]=nums[last_idx];
            last_idx=prev_idx[last_idx];
            idx--;
        }
        return res;
    }
};