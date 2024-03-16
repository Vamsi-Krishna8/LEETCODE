//Explanation Link : https://leetcode.com/problems/contiguous-array/solutions/4882018/simplestt-explanation-bruteforce-hashmap-c/?envType=daily-question&envId=2024-03-16

//Brute Force

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int zeroes=0,ones=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0) zeroes++;
                else ones++;
                if(zeroes==ones) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};

//HashMap

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1; // sets a starting point before the array begins, helping to count the length of balanced parts that start right from the first element.
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]==0) ? -1 : 1;
            if(mp.find(sum)!=mp.end()) ans=max(ans,i-mp[sum]);  //If sum has been seen before, a balanced subarray is found.
            else mp[sum]=i; //first occurrence of this sum
        }
        return ans;
    }
};