class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long >dis(n,LLONG_MAX);
        vector<long long>ways(n,0);
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>pq;
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});
       
        while(!pq.empty()){
            long long  time=pq.top().first;
            int curr=pq.top().second;
            pq.pop();
            if(time>dis[curr])continue;
            for(auto it:adj[curr]){
                long long t=it.second;
                int adjnode=it.first;
                if(time+t<dis[adjnode]){
                    pq.push({t+time,adjnode});
                    dis[adjnode]=t+time;
                    ways[adjnode]=ways[curr];
                }
                else if(time +t==dis[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[curr])%(7+1000000000);
                }
            }
        }

    return ways[n-1];}
};