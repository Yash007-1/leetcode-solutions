class Solution {
public:
    int f(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {

        if (i > j)
            return 0;
        if (dp[i-1][j-1] != -1)
            return dp[i-1][j-1];
        int mx = 0;
        for (int k = i; k <= j; k++) {
            int left = f(nums, i, k - 1, dp);
            int right = f(nums, k + 1, j, dp);
            mx = max(mx, left + right + nums[i - 1] * nums[k] * nums[j + 1]);
        }
        return dp[i-1][j-1] = mx;
    }
    int maxCoins(vector<int>& nums) {
  int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
      
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return f(nums, 1, n, dp);
    }
};