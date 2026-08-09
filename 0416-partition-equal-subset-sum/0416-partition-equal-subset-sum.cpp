class Solution {
public:
bool f(vector<int>&nums,int idx,int tgt ,vector<vector<int>>&dp){
    if(tgt==0)return true;
    if(idx==0)return nums[0]==tgt;
    if( dp[idx][tgt]!=-1)return dp[idx][tgt];
    bool notake=f(nums,idx-1,tgt,dp);
    bool take=false;
    if(nums[idx]<=tgt)take=f(nums,idx-1,tgt-nums[idx],dp);
    return dp[idx][tgt]=take||notake;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
       
        int sum=0;
        for(auto i:nums)sum+=i;
        if(sum%2!=0)return false;
         vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return f(nums,n-1,sum/2,dp);
    }
};