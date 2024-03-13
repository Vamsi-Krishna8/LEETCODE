//With Sorting

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> res;
        unordered_map<string,vector<string> > mp;
        for(int i=0;i<str.size();i++){
            string temp=str[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str[i]);
        }
        for(auto x:mp) res.push_back(x.second);
        return res;
    }
};

//Without Sorting

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> res;
        unordered_map<string,vector<string> > mp;
        for(int i=0;i<str.size();i++){
            string temp=str[i];
            vector<int> freq(26,0);
            for(int i=0;i<temp.size();i++){
                freq[temp[i]-'a']+=1;
            }
            string sort_word="";
            for(int i=0;i<26;i++){
                while(freq[i]--){
                    sort_word+=i+'a';
                }
            }
            mp[sort_word].push_back(temp);
        }
        for(auto x:mp) res.push_back(x.second);
        return res;
    }
};