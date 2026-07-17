class Solution {
public:
   void bfs(vector<vector<int>>&image,int sr,int sc,int og,int color,vector<vector<int>>&vis){
    
     queue<pair<int,int>>q;
     q.push({sr,sc});
     while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        vis[row][col]=1;
        q.pop();
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        for(int  k=0;k<4;k++){
            
                int nrow=row+drow[k];
                int ncol=dcol[k]+col;
                if(nrow>=0&&nrow<image.size()&&ncol>=0&&ncol<image[0].size()&&vis[nrow][ncol]==0&&image[nrow][ncol]==og){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            
        }
     }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ogcolor=image[sr][sc];
        image[sr][sc]=color;
        bfs(image,sr,sc,ogcolor,color,vis);

    return image;}
};