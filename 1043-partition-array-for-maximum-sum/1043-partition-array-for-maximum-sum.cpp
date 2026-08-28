class Solution {
public:
    int f(vector<int>&nums,int i,int k,vector<int>&dp){
        
        if(i==nums.size()){
            return dp[i]=0;
        }
        if(dp[i]!=-1)return dp[i];
        int mx=nums[i];
        int len=1;
        int ans=0;
        for(int x=i;x<min(i+k,(int)nums.size());x++){
            mx=max(mx,nums[x]);
             len=x-i+1;
            ans=max(ans,mx*len+f(nums,x+1,k,dp));
           
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int>dp(n+1,0);
       for(int i=n-1;i>=0;i--){
           int mx=nums[i];
        int len=1;
        int ans=0;
        for(int x=i;x<min(i+k,n);x++){
            mx=max(mx,nums[x]);
             len=x-i+1;
            ans=max(ans,mx*len+dp[x+1]);
           
        }
         dp[i]=ans;
       }
        return dp[0];
    }
};