//MajorityElement 1

//Boye-Moore's Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majEle=-1;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count==0){
                majEle=nums[i];
                count=1;
            }
            else if(nums[i]==majEle) count++;
            else count--;
        }
        return majEle;
    }
};

//MajorityElement 2

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        int majEle1=-1;

        int count2=0;
        int majEle2=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==majEle1) count1++;
            else if(nums[i]==majEle2) count2++;
            else if(count1==0){
                majEle1=nums[i];
                count1=1;
            }
            else if(count2==0){
                majEle2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        int c1=0,c2=0;
        for(auto x:nums){
            if(x==majEle1) c1++;
            else if(x==majEle2) c2++;
        }
        if(c1>n/3) ans.push_back(majEle1);
        if(c2>n/3) ans.push_back(majEle2);
        return ans;
    }
};