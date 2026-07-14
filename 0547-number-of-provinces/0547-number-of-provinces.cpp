class Solution {
public:
    void dfs(int i,vector<int>adj[],vector<int>& visited){

        if(visited[i]==1)return;
        visited[i]=1;
       for(auto u:adj[i]){
        if(visited[u]==0)
        dfs(u,adj,visited);
        
       }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>adj[isConnected.size()];
        vector<int> visited(isConnected[0].size()+1,0);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]){
                  adj[i].push_back(j);
                  adj[j].push_back(i);}
            }
        }
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]==0){
                dfs(i,adj,visited);
                count++;
            }
        }
    return count;}
};