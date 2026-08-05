class Solution {
public:
    int bfs(unordered_map<int, vector<int>> &adj, vector<int>& indeg,
             queue<int>& q , vector<int>&ans ) {
        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++ ;
            ans.push_back(u);
            for (auto& it : adj[u]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        return count;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;
        vector<int>ans;
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<int> indeg(n, 0);

        for (auto& it : adj) {
            for (auto x : it.second) {
                indeg[x]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        int a = bfs(adj, indeg, q , ans);

        if (a==n) return ans ;
        vector<int>dummy ;
        return dummy ;
    
    }
};