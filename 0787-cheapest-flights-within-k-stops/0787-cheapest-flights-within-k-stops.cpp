class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        vector<vector<int>> price(n, vector<int>(k + 2, INT_MAX));

        price[src][0] = 0;

        pq.push({0, src, 0});

        while (!pq.empty()) {
            int d = pq.top()[0];
            int u = pq.top()[1];
            int stop = pq.top()[2];

            pq.pop();

            if (stop == k + 1) {
                continue;
            }

            for (auto& it : adj[u]) {
                int v = it.first;
                int dt = it.second;

                int newstop = stop + 1;

                if (dt + d < price[v][newstop]) {
                    price[v][newstop] = d + dt;
                    pq.push({price[v][newstop], v, newstop});
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i <= k + 1; i++) {
            ans = min(ans, price[dst][i]);
        }

        if (ans == INT_MAX){
            return -1;
            }
        return ans;
    }
};