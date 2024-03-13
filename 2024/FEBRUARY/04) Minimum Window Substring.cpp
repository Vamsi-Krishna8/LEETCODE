class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m>n) return "";
        unordered_map<char,int> mp;
        for(auto &x:t) mp[x]++;
        int i=0,j=0;
        int count=m;
        int start_idx=0;
        int windowSize=INT_MAX;
        while(j<n){
            if(mp[s[j]]>0) count--;
            mp[s[j]]--;
            while(count==0){
                int currWindowSize=j-i+1;
                if(windowSize>currWindowSize){
                    windowSize=currWindowSize;
                    start_idx=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) count++;
                i++;
            }
            j++;
        }
        return windowSize==INT_MAX ? "" : s.substr(start_idx,windowSize);
    }
};