class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> price(n, 1e9);
        queue<pair<pair<int, int>, int>> q;
        price[src] = 0;
        int cprice = -1;
        q.push({{0, src}, 0});
        while (!q.empty()) {
            int p = q.front().first.first;
            int city = q.front().first.second;
            int stops = q.front().second;
            if (city == dst && stops - 1 <= k) {
                if (cprice < 0)
                    cprice = p;
                else
                    cprice = min(cprice, p);
            }

            q.pop();
            if (stops > k)
                continue;
            for (auto it : adj[city]) {
                int egw = it.second;
                int adjnode = it.first;
                if (p + egw < price[adjnode]) {
                    q.push({{p + egw, adjnode}, stops + 1});
                    price[adjnode] = p + egw;
                }
            }
        }
        return cprice;
    }
};