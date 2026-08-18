class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);

        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>>dist(n+1,vector<int>(2,INT_MAX));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[1][0] = 0;
        pq.push({0, 1});

        while(!pq.empty()) {

            int currTime = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(int v:adj[u]) {
                int newTime =currTime;

                if(newTime%(2* change) >=change) {
                    newTime = (newTime/(2*change) +1)*(2 *change);
                }
                newTime += time;

                if(newTime < dist[v][0]) {
                    dist[v][1] = dist[v][0];
                    dist[v][0] = newTime;
                    pq.push({newTime, v});
                }
                else if(newTime > dist[v][0] && newTime < dist[v][1]) {
                    dist[v][1] = newTime;


                    pq.push({newTime, v});
                }
            }
        }

        return dist[n][1];
    }
};