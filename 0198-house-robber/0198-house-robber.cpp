class Solution {
public:
      int helper(vector<int>&nums,int idx,vector<int>&dp){
        if(idx==0)return nums[0];
       if(idx<0)return 0;
       if(dp[idx]!=-1)return dp[idx];
        int  take=nums[idx]+helper(nums,idx-2,dp);
        int n_take=helper(nums,idx-1,dp);
        return dp[idx]=max(take,n_take);
      }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)take=nums[i]+dp[i-2];
            int n_take=dp[i-1];
            dp[i]=max(take,n_take);
        }
        
      return dp[nums.size()-1];
    }
};