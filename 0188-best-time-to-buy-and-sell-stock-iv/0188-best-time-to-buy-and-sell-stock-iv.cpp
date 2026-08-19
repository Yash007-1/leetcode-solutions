class Solution {
public:
 int f(vector<int>& prices, int idx, int buy, vector<vector<vector<int>>>& dp, int tran) {
        if (tran < 0)
            return 0;
        if (idx == prices.size()) {
            return 0;
        }
        if (dp[idx][buy][tran] != -1)
            return dp[idx][buy][tran];
        if (!buy) {
            return dp[idx][buy][tran] =
                       max(prices[idx] + f(prices, idx + 1, 1, dp, tran - 1),
                           f(prices, idx + 1, 0, dp, tran));
        } else {

            return dp[idx][buy][tran] =
                       max(-prices[idx] + f(prices, idx + 1, 0, dp, tran),
                           f(prices, idx + 1, 1, dp, tran));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>curr(2,vector<int>(k+1,0)),next(2,vector<int>(k+1,0));
       
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int t=1;t<=k;t++)
                if(!j)curr[j][t]=max(prices[i]+next[1][t-1],next[0][t]);
                else curr[j][t]=max(-prices[i]+next[0][t],next[1][t]);
            }
            next=curr;
        }
        return next[1][k];
    }
    
};