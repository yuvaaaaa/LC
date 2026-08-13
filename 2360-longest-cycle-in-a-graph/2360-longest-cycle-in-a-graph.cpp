class Solution {
public:
    void topo(unordered_map<int, vector<int>>& adj, vector<bool>& vis, int u,
              stack<int>& st) {
        vis[u] = true;
        for (auto& v : adj[u]) {
            if (!vis[v]) {
                topo(adj, vis, v, st);
            }
        }
        st.push(u);
        return;
    }
    void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& vis, int u,
             unordered_map<int, int>& mp, int i) {
        vis[u] = true;
        mp[i]++;

        for (auto& v : adj[u]) {
            if (!vis[v]) {
                dfs(adj, vis, v, mp, i);
            }
        }
        return;
    }
    int longestCycle(vector<int>& edges) {

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }
        int n = edges.size();

        stack<int> st;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                topo(adj, vis, i, st);
            }
        }

        fill(vis.begin(), vis.end(), false);

        unordered_map<int, vector<int>> adj2;

        for (int i = 0; i < n; i++) {
            for (auto& it : adj[i]) {
                adj2[it].push_back(i);
            }
        }
        int i = 0;
        unordered_map<int, int> mp;

        while (!st.empty()) {
            int curr = st.top();
            st.pop();

            if (!vis[curr]) {
                dfs(adj2, vis, curr, mp, i);
                i++;
            }
        }
        int ans = -1;

        for (int j = 0; j < i; j++) {
            ans = max(ans, mp[j]);
        }

        if(ans <= 1 ) return -1;

        return ans;
    }
};