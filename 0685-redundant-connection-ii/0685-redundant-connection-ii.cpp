class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv)
            return false;

        parent[pu] = pv;
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> par(n+1, 0);
        vector<int> first;
        vector<int> second ;

        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];

            if(par[v] == 0) {
                par[v] = u;
            }
            else {
                first = {par[v], v};
                second = {u, v};
                break;
            }
        }

        parent.resize(n + 1);
        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(auto &it : edges) {
            if(!second.empty() && it== second)
                continue;

            if(unite(it[0], it[1])==false) {
                if(first.empty()){

                    return it;
                }

                return first;
            }
        }

        return second;
    }
};