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
       vector<int>up(n,1e9);
       vector<int>curr(n,0);
       
        int ans=1e9;
       for(int i=0;i<m;i++){
        for(int j=0;j<triangle[i].size();j++){
            if(i==0&&j==0){curr[0]=triangle[0][0];
            break;}
            else{
                int uleft=1e9;
              int u=1e9;
                if(j)uleft=up[j-1];
                if(j!=triangle[i].size()-1)u=up[j];
                curr[j]=triangle[i][j]+min(uleft,u);
            }
        }
        up=curr;
       }
       for(int i=0;i<n;i++){
        ans=min(ans,up[i]);
       }
return ans;
    }
};