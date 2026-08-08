class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         
        // code here
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1)continue;
                if(i==0&&j==0)dp[0][0]=1;
                else{
                    int left=0;
                    int up=0;
                    if(i)left=dp[i-1][j];
                    if(j)up=dp[i][j-1];
                    dp[i][j]=left+up;
                }
                
            }
        }
        return dp[m-1][n-1];
    

    }
};