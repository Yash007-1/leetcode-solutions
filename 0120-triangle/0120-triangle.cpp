class Solution {
public:
int helper(vector<vector<int>>&tri,int i,int j,vector<vector<int>>&dp){
     if(i==0&&j==0)return tri[0][0];
     if(dp[i][j]!=-1)return dp[i][j];
     int uleft=1e9;
     int up=1e9;
     if(i&&j>0)uleft=helper(tri,i-1,j-1,dp);
     if(i>0&&j!=tri[i].size()-1)up=helper(tri,i-1,j,dp);
     return dp[i][j]=tri[i][j]+min(uleft,up);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=1e9;
        for(int i=0;i<n;i++){
            int curr=helper(triangle,m-1,i,dp);
            ans=min(ans,curr);
        }
return ans;
    }
};