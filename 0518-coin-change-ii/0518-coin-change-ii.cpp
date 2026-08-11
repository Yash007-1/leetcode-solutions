class Solution {
public:
int f(vector<int>nums,int idx,int amt,vector<vector<int>>&dp){
    if(amt==0)return 1;
    if(idx==0){
        if(amt%nums[0]==0)return 1;
        else return 0;
    }
    if(dp[idx][amt]!=-1)return dp[idx][amt];
    int ntake=f(nums,idx-1,amt,dp);
    int take=0;
    if(nums[idx]<=amt)take=f(nums,idx,amt-nums[idx],dp);
    return dp[idx][amt]=ntake+take;
}
    int change(int amount, vector<int>& coins) {
          int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
      
        return f(coins,n-1,amount,dp);
    }
};