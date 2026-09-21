class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> ans(k, 0);
        vector<vector<long long>> dp(n, vector<long long>(k, 0));

        for (int j = 0; j < n; j++) {
            int rem = nums[j] % k;

            
            dp[j][rem]++;
           
            if (j > 0) {
                for (int r = 0; r < k; r++) {
                    int prorem = (r * rem) % k;
                    dp[j][prorem] += dp[j - 1][r];
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int r = 0; r < k; r++) {
                ans[r] += dp[j][r];
            }
        }

        return ans;
    }
};