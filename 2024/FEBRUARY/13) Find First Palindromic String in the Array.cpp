//METHOD 1

class Solution {
public:
    bool check(string s,int i,int j){
        if(i>j) return true;
        if(s[i]==s[j]){
            return check(s,i+1,j-1);
        }
        return false;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto x:words){
            if(check(x,0,x.size()-1)){
                return x;
            }
        }
        return "";
    }
};

//METHOD 2 (Using std::reverse())

class Solution {
public:
    bool check(string s){
        string temp=s;
        reverse(temp.begin(),temp.end());
        return s==temp;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto x:words){
            if(check(x)){
                return x;
            }
        }
        return "";
    }
};

//METHOD 3 (Using copy string)

class Solution {
public:
    bool check(string s){
        string temp=string(s.rbegin(),s.rend());
        return s==temp;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto x:words){
            if(check(x)){
                return x;
            }
        }
        return "";
    }
};

//METHOD 4 (Using std::equal)

class Solution {
public:
    bool check(string s){
        int n=s.size();
        return equal(s.begin(),s.begin()+n/2,s.rbegin());
    }
    string firstPalindrome(vector<string>& words) {
        for(auto x:words){
            if(check(x)){
                return x;
            }
        }
        return "";
    }
};