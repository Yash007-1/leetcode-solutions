class Solution {
public:
    int f(vector<int>&nums,int k,int i,int j,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(j-i<k){
            int m=0;
            for(int x=i;x<=j;x++){
             m=max(nums[x],m);
            }
            return dp[i][j]=(j-i+1)*m;
        }
        
        int ms=0;
        for(int x=i;x<j;x++){
          int left=f(nums,k,i,x,dp);
          int right=f(nums,k,x+1,j,dp);
          int sum=left+right;
          ms=max(ms,sum);

        }
        return dp[i][j]=ms;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(arr,k,0,n-1,dp);
    }
};