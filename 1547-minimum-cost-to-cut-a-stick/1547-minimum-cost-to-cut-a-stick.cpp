class Solution {
public:
    int f(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if (j - i <= 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int minc = 1e9;
        for (int k = i + 1; k < j; k++) {
            int left = f(cuts, i, k, dp);
            int right = f(cuts, k, j, dp);
            minc = min(minc, left + right + cuts[j] - cuts[i]);
        }
        return dp[i][j] = minc;
    }
    int minCost(int n, vector<int>& cuts) {

        vector<int> arr = cuts;
        arr.push_back(n);
        arr.push_back(0);
        sort(arr.begin(), arr.end());
        int m = arr.size();
        vector<vector<int>> dp(m, vector<int>(m, 1e9));
        for (int i = 0; i < m - 1; i++) {
            dp[i][i] = 0;
            dp[i][i + 1] = 0;
        }
        dp[m - 1][m - 1] = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 2; j < m; j++) {
                int minc = 1e9;
                for (int k = i + 1; k < j; k++) {
                    int left = dp[i][k];
                    int right = dp[k][j];
                    minc = min(minc, left + right + arr[j] - arr[i]);
                }
                dp[i][j] = minc;
            }
        }
        return  dp[0][m - 1];
    }
};