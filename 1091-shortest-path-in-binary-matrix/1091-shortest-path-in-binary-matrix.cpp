class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]==1)return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vis(n,vector<int>(m,1e9));
        vis[0][0]=1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int length=pq.top().first;
            pq.pop();
            if(r==n-1&&c==m-1)return length;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=r+i;
                    int nc=c+j;
                    if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==0){
                        if(length+1<vis[nr][nc]){
                            pq.push({length+1,{nr,nc}});
                            vis[nr][nc]=length+1;
                        }
                    }
                }
            }
        }
    return -1;}
};