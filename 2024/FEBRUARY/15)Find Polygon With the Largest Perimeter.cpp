class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long currSum=0;
        long long perimeter=0;

        for(int i=0;i<n;i++){
            if(nums[i]<currSum){
                perimeter=currSum+nums[i];
            }
            currSum+=nums[i];
        }   
        return (perimeter!=0) ? perimeter : -1;
    }
};