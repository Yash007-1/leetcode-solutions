class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
            
             
        }
        vector<int>vis(n,0);
       vis[k]++;
int flag=true;
        queue<int>q;
        q.push(k);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]!=1){vis[it]++;
                q.push(it);}

            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                for(auto it:adj[i]){
                    if(vis[it]==1){
                        flag=false;
                        break;
                    }
                }
            }
        }
        vector<int>ans;
        if(flag){
           for(int i=0;i<n;i++){
            if(vis[i]==0)
                ans.push_back(i);
            } 
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
    return ans;}
};