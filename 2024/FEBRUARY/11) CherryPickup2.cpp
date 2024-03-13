// Refer This : https://www.youtube.com/watch?v=Pd9wdXe8S6I

//RECURSION

class Solution {
public:
    int n,m;
    int solve(vector<vector<int>>& grid,int row,int col1,int col2){
        if(row>=n) return 0;
        int cherryCount=grid[row][col1];
        if(col1!=col2) cherryCount+=grid[row][col2];
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int newRow=row+1;
                int newCol1=col1+i;
                int newCol2=col2+j;
                if(newCol1>=0 && newCol1<m && newCol2>=0 && newCol2<m){
                    ans=max(ans,solve(grid,newRow,newCol1,newCol2));
                }
            }
        }
        return cherryCount+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        return solve(grid,0,0,m-1);
    }
};

//MEMOIZATION

class Solution {
public:
    int n,m;
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid,int row,int col1,int col2){
        if(row>=n) return 0;
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        int cherryCount=grid[row][col1];
        if(col1!=col2) cherryCount+=grid[row][col2];
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int newRow=row+1;
                int newCol1=col1+i;
                int newCol2=col2+j;
                if(newCol1>=0 && newCol1<m && newCol2>=0 && newCol2<m){
                    ans=max(ans,solve(grid,newRow,newCol1,newCol2));
                }
            }
        }
        return dp[row][col1][col2]=cherryCount+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,m-1);
    }
};