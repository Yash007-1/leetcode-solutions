class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> radj[n];
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                radj[it].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> safe;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
               
            }
        }
         while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    safe.push_back(curr);
                    for (auto it : radj[curr]) {
                        indegree[it]--;
                        if (!indegree[it])
                            q.push(it);
                    }
                }
        sort(safe.begin(),safe.end());
        return safe;
    }
};