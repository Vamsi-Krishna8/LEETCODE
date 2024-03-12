class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto x:s) mp[x]++;
        priority_queue<pair<int,char>> pq;
        for(auto x:mp) pq.push({x.second,x.first});
        string ans="";
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            while(x.first--){
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};