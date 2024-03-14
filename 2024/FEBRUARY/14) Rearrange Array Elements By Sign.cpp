//Method 1

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for(auto x:nums){
            if(x>0) pos.push_back(x);
            else neg.push_back(x);
        }
        vector<int> res;
        int p=0;
        int i=0,j=0;
        while(i<pos.size() || j<neg.size()){
            if(p%2==0) {
                res.push_back(pos[i]);
                i++;
            }
            else{
                res.push_back(neg[j]);
                j++;
            }
            p++;
        }
        return res;
    }
};

//Method 2

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int i=0,j=1;
        for(auto x:nums){
            if(x>0){
                res[i]=x;
                i+=2;
            }
            else{
                res[j]=x;
                j+=2;
            }
        }
        return res;
        
    }
};