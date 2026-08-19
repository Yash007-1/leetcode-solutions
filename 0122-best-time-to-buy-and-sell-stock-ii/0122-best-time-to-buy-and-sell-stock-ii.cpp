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
        vector<int>curr(2,0),next(2,0);
       
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(!j)curr[j]=max(prices[i]+next[1],next[0]);
                else curr[j]=max(-prices[i]+next[0],next[1]);
            }
            next=curr;
        }
        return next[1];
    }
};