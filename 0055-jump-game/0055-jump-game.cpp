class Solution {
public:
    bool f(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size())return false;
        
        if(i==nums.size()-1)return true;
        if(dp[i]!=-1)return dp[i];
        bool flag=false;

        for(int x=1;x<=nums[i];x++){
            flag=flag||f(nums,i+x,dp);
        }
        return dp[i]=flag;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};