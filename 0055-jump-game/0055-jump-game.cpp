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
        int n=nums.size();
        //return f(nums,0,dp);
        int farthest=0;
        for(int i=0;i<n;i++){
            if(farthest>=i)
            farthest=max(farthest,i+nums[i]);
            if(farthest>=n-1)return true;
        }
        return farthest>=n-1;
    }
};