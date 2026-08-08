class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> up(n, 1e9);
        vector<int> curr(n, 0);
        curr[0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                int u=up[j];
                int left = 1e9;
                if (j)
                    left = curr[j - 1];

                curr[j] = grid[i][j] + min(left, u);
            }

            up = curr;
        }
        return up[n - 1];
    }
};