class Solution {
public:
    int bfs(unordered_map<int, vector<int>> &adj, vector<int>& indeg,
             queue<int>& q ) {
        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++ ;
            for (auto& it : adj[u]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        return count;
    } 

    void dfs(unordered_map<int, vector<int>> &adj ,vector<bool>&vis , stack<int>&st , int i ){

        for(auto &it :adj[i]){
            vis[i]=true;
            if(vis[it]== false){
                dfs(adj,vis,st,it);
            }
        }
        st.push(i);
        return ;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<bool> vis(n, false);
        vector<int>indeg(n,0);
        for (auto& it : adj) {
            for (auto x : it.second) {
                indeg[x]++;
            }
        }

        // queue<int> q;
        stack<int>st;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                dfs(adj,vis,st,i);
        }

        // int a = bfs(adj, indeg, q);

        // if (a==n) return true ;
        // return false ;

        unordered_map<int,int>dt;
        int time =0;

        while(!st.empty()){
            int curr = st.top();
            st.pop();
            dt[curr] = time ;
            time ++ ;
        }

        for( int i=0;i<n;i++){
            for(auto &it : adj[i]){
                if(dt[i]>=dt[it]){
                    return false;
                }
            }
        }
        return true;

    }
};