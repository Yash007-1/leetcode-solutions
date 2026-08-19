class Solution {
public:
int f(vector<int>&prices,int idx,int buy,vector<vector<int>>&dp){
    if(idx==prices.size()){
     return 0;
    }
    if(dp[idx][buy]!=-1)return dp[idx][buy];
    if(!buy){
      return dp[idx][buy]=max(prices[idx]+f(prices,idx+1,1,dp),f(prices,idx+1,0,dp));
    }
    else {
       
        return dp[idx][buy]=max(-prices[idx]+f(prices,idx+1,0,dp),f(prices,idx+1,1,dp));
        
    }
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(prices,0,1,dp);
    }
};