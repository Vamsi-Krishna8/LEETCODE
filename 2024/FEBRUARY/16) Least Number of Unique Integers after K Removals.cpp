//Method 1

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        vector<int> freq;
        for(auto x:arr) mp[x]++;
        for(auto x:mp) freq.push_back(x.second);
        sort(freq.begin(),freq.end());
        for(int i=0;i<freq.size();i++){
            k-=freq[i];
            if(k<0) return freq.size()-i;
        }
        return 0;
    }
};


//Method 2

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto x:arr) mp[x]++;
        priority_queue<int,vector<int>,greater<int> > pq; 
        for(auto x:mp) pq.push(x.second);
        while(!pq.empty()){
            k-=pq.top();
            if(k<0) return pq.size();
            pq.pop();
        }
        return 0;
    }
};

//Method 3

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto x:arr) mp[x]++;
        vector<int> countFreq(n);
        for(auto x:mp){
            countFreq[x.second]++;
        }
        int ans=mp.size();
        for(int i=0;i<countFreq.size();i++){
            int canDelete=min(k/i,countFreq[i]);
            k-=canDelete*i;
            ans-=canDelete;
            if(k<=i) return ans;
        }
        return 0;
    }
};