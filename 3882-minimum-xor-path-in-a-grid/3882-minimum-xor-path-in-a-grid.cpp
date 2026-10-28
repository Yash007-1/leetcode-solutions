class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j, int curr,
          vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (i == n - 1 && j == m - 1)
            return grid[i][j] ^ curr;
        if (dp[i][j][curr] != -1)
            return dp[i][j][curr];
        int right = 1e9, down = 1e9;
        if (j < m - 1)
            right = f(grid, i, j + 1, grid[i][j] ^ curr, dp);
        if (i < n - 1)
            down = f(grid, i + 1, j, grid[i][j] ^ curr, dp);
        return dp[i][j][curr] = min(right, down);
    }
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(1024, -1)));
        int ans = f(grid, 0, 0, 0, dp);

        return ans;
    }
};