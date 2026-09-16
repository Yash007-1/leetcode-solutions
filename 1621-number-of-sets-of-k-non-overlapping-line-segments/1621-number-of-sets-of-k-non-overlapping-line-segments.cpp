class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        vector<vector<long long>> pref(n + 1, vector<long long>(k + 1, 0));

        for (int i = 1; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                dp[i][j] = dp[i - 1][j];

            
                dp[i][j] = (dp[i][j] + pref[i - 1][j]) % MOD;

               
               pref[i][j] = (pref[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

        return dp[n][k];
    }
};