class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dis(row,vector<int>(col,1e9));
        dis[0][0]=0;
        int maxeffort=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int effort=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==row-1&&c==col-1)return effort;
            int d_r[]={-1,0,1,0};
            int d_c[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow=r+d_r[i];
                int ncol=c+d_c[i];
            if(nrow>=0&&nrow<row&&ncol>=0&&ncol<col){
                int neweffort=max(abs(heights[nrow][ncol]-heights[r][c]),effort);
                if(neweffort<dis[nrow][ncol]){
                    pq.push({neweffort,{nrow,ncol}});
                    dis[nrow][ncol]=neweffort;
                   
                }
            }
            }
        }
    return 0;}
};