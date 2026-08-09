class Solution {
public:
    // bool isSafe(vector<pair<int, int>>& dirs, vector<vector<int>>& heights,
    //             int i, int j, int m, int n) {
    //     for (auto& it : dirs) {
    //         int x = it.first + i;
    //         int y = it.seccond + j;

    //         if (x < 0 || y < 0 || x > m || y > n) {
    //             return false;
    //         }
    //     }
    // }
    int minimumEffortPath(vector<vector<int>>& heights) {

        unordered_map<int, vector<pair<int, int>>> adj;
        int m = heights.size();
        int n = heights[0].size();
        int node = 0;

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int u = i * n + j;
                for (auto& it : dirs) {
                    int x = it.first + i;
                    int y = it.second + j;
                    int v = x * n + y;

                    if (x < 0 || y < 0 || x >= m || y >= n) {
                        continue;
                    }

                    adj[u].push_back({v, abs(heights[i][j] - heights[x][y])});
                }
            }
        }

        vector<int> dist(m * n, INT_MAX);
        set<pair<int, int>> st;
        dist[0]=0;
        st.insert({0, 0});

        while (!st.empty()) {
            int dt = st.begin()->first;
            int u = st.begin()->second;
            st.erase(st.begin());
            for (auto& it : adj[u]) {
                int v = it.first;
                int d = it.second;
                int h = max(dt,d);

                if (h < dist[v]) {
                    dist[v] = h;
                    st.insert({dist[v], v});
                }
            }
        }
            return dist[m*n-1];
    }
};