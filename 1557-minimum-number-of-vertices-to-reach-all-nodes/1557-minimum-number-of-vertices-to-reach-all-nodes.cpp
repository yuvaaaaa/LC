class Solution {
public:
    // void dfs (vector<bool>&vis , unordered_map<int,vector<int>>&adj , int u ){
        
    //     vis[u] = true ;
    //     for(auto &it : adj[u]){
    //         if(vis[it]== false){
    //             dfs(vis , adj , it);
    //         }
    //     }
    //     return ;
    // }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<int> indeg(n, 0);

        for (auto& it : adj) {
            for (auto x : it.second) {
                indeg[x]++;
            }
        }
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0){
                ans.push_back(i);
            }
        }

       return ans ;
    }
};