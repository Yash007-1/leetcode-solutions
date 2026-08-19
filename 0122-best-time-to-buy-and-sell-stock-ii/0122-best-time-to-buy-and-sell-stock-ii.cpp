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
        int n=prices.size();
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        dp[prices.size()][0]=dp[prices.size()][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(!j)dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                else dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            }
        }
        return dp[0][1];
    }
};