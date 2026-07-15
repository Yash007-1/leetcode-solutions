class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid,
         vector<vector<int>>& visited) {

    queue<pair<int,int>> q;
    q.push({i, j});
    visited[i][j] = 1;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];

            if(nrow >= 0 && nrow < grid.size() &&
               ncol >= 0 && ncol < grid[0].size() &&
               !visited[nrow][ncol] &&
               grid[nrow][ncol] == '1') {

                visited[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}
         

         
    int numIslands(vector<vector<char>>& grid) {
       vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                  if(grid[i][j]=='1'&&visited[i][j]==0){
                    count++;
                    bfs(i,j,grid,visited);
                  }
            }
        }
    return count;}
};