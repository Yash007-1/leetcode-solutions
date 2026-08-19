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
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(k, -1)));
        return f(prices, 0, 1, dp, k-1);
    }
};