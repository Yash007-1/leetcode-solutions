class Solution {
public:
    bool f(vector<int>& piles, int i, int j, int alice, int bob, bool chance,
           vector<vector<int>>& dp) {
        if (i == j) {
            if (chance)
                return dp[i][j] = alice + piles[i] > bob;
            else
                return dp[i][j] = alice > bob + piles[i];
        };
        if (dp[i][j] != -1)
            return (bool)dp[i][j];
        if (chance) {
            return dp[i][j] =
                       f(piles, i + 1, j, alice + piles[i], bob, false, dp) ||
                       f(piles, i, j - 1, alice + piles[j], bob, false, dp);
        } else
            return dp[i][j] =
                       f(piles, i + 1, j, alice, bob + piles[i], true, dp) ||
                       f(piles, i, j - 1, alice, bob + piles[j], true, dp);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(piles, 0, piles.size() - 1, 0, 0, true, dp);
    }
};