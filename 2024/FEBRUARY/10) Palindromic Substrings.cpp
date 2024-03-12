//BRUTE FORCE

class Solution {
public:

    bool check(string s,int i,int j){
        if(i>j) return true;
        if(s[i]==s[j]){
            return check(s,i+1,j-1);
        }
        return false;
    }

    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)) count++;
            }
        }
        return count;
    }
};

//BRUTE FORCE MEMOIZATON

class Solution {
public:
    int dp[1001][1001];
    bool check(string s,int i,int j){
        if(i>j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=check(s,i+1,j-1);
        }
        return dp[i][j]=false;
    }

    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)) count++;
            }
        }
        return count;
    }
};

//TABULATION

class Solution {
public:
    /*
        State => dp[i][j] = True => S[i:j] is a palindrome
                 dp[i][j] = False => S[i:j] is not a palindrome

        dp[i][i]=True => single character length string is always palindrome
        2 Length substring => if i+1=j then if s[i]==s[j] then True

    */
    int dp[1001][1001];
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        memset(dp,0,sizeof(dp));
        for(int len=1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(i==j) dp[i][j]=1;
                else if(i+1==j){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]==1){
                        dp[i][j]=1;
                    }
                }
                if(dp[i][j]==1) count++;
            }
        }
        return count;
        
    }
};

//MID-POINT APPROACH

class Solution {
public:
    int count=0;
    void fun(string &s,int i,int j,int n){
        while(i>=0 && j<n && s[i]==s[j]){
            count++;
            i--,j++;
        }
    }
    int countSubstrings(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            fun(s,i,i,n);
            fun(s,i,i+1,n);
        }
        return count;
    }
};