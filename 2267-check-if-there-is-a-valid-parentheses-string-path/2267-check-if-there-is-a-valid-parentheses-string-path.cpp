class Solution {
public:
    int f(vector<vector<char>>&grid,int i,int j,int paren,vector<vector<vector<int>>>&dp){
        if(grid[i][j]=='(')paren++;
        else paren--;
        if(paren<0)return false;
        int n=grid.size();
        int m=grid[0].size();

        if(i==n-1&&j==m-1)return paren==0&&grid[i][j]==')';
    if(dp[i][j][paren]!=-1)return dp[i][j][paren];
        int ncol=j+1;
        int nrow=i+1;
        int right=false;
        int down=false;
        if(j+1<m){
            right=f(grid,i,j+1,paren,dp);
        }
        if(i+1<n){
            down=f(grid,i+1,j,paren,dp);
        }
        return dp[i][j][paren]=right||down;

    }
    bool hasValidPath(vector<vector<char>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m+n+1,-1)));
        if(grid[0][0]==')')return false;
        return f(grid,0,0,0,dp);
    }
};