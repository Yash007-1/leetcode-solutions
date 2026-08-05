class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
            
             
        }
        unordered_map<int,int>m;
        m[k]++;
int flag=true;
        queue<int>q;
        q.push(k);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(m[it]!=1){m[it]++;
                q.push(it);}

            }
        }
        for(int i=0;i<n;i++){
            if(m[i]==0){
                for(auto it:adj[i]){
                    if(m[it]==1){
                        flag=false;
                        break;
                    }
                }
            }
        }
        vector<int>ans;
        if(flag){
           for(int i=0;i<n;i++){
            if(m[i]==0)
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