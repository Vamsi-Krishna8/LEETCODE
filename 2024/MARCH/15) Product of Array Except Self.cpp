//Explanation Link :https://leetcode.com/problems/product-of-array-except-self/solutions/4881321/4approaches-simple-beginner-friendly-understanding-c/


//Brute Force

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1); 

        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < n; ++j) { 
                if (i != j) { 
                    result[i] *= nums[j]; 
                }
            }
        }

        return result;
    }
};

//Approach 2

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int zeroCount = 0;
        for (int num : nums) {
            if (num != 0) totalProduct *= num;
            else zeroCount++;
        }

        vector<int> result(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 1) continue;
            if (zeroCount == 0) result[i] = totalProduct / nums[i];
            else if (nums[i] == 0) result[i] = totalProduct;
        }

        return result;
    }
};

//Approach 3

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1),suffix(n, 1),result(n);
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for(int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; ++i) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};

//Approach 4

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0]=1;
        for(int i=1;i<n;i++){
            result[i]=nums[i-1]*result[i-1];
        }
        int rightProduct=1;
        for(int i=n-1;i>=0;i--){
            result[i]=result[i]*rightProduct;
            rightProduct*=nums[i];
        }
        return result;
    }
};