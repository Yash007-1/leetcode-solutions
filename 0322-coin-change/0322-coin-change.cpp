class Solution {
public:
int f(vector<int>&coins,int idx,int amt,vector<vector<int>>&dp){
    if(amt==0)return 0;
    if(idx==0){
        if(amt%coins[idx]!=0)return INT_MAX-1;
        else return amt/coins[0];
    }
    if(dp[idx][amt]!=-1)return dp[idx][amt];
    int ntake=f(coins,idx-1,amt,dp);
    int take=INT_MAX-1;
    if(amt>=coins[idx])take=1+f(coins,idx,amt-coins[idx],dp);
    return dp[idx][amt]=min(take,ntake);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=f(coins,coins.size()-1,amount,dp);
        if(ans==INT_MAX-1)return -1;
        return ans;
    }
};