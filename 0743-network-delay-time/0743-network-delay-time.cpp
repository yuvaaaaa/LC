class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        set<pair<int, int>> st;

        st.insert({0, k});

        while (!st.empty()) {
            int d = st.begin()->first;
            int u = st.begin()->second;
            st.erase(st.begin());
            for (auto& it : adj[u]) {
                int v = it.first;
                int dt = it.second;
                if (d + dt < dist[v]) {
                    if (dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    dist[v] = d + dt;
                    st.insert({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i=1 ;i<=n;i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};