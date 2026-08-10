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
            
        vector<int>price(n, INT_MAX);

        price[src] = 0;

        pq.push({0, src, 0});

        while (!pq.empty()) {
            int d = pq.top()[2];
            int u = pq.top()[1];
            int stop = pq.top()[0];

            pq.pop();

            if (stop == k + 1) {
                continue;
            }

            for (auto& it : adj[u]) {
                int v = it.first;
                int dt = it.second;

                int newstop = stop + 1;

                if (dt + d < price[v]) {
                    price[v]= d + dt;
                    pq.push({newstop,v,price[v] });
                }
            }
        }


        if(price[dst]==INT_MAX) return -1;
        return price[dst];
    }
};