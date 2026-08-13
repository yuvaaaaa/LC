class Solution {
public:
    int time =0 ;
    vector<vector<int>>ans ;
    void tarjan (unordered_map<int,vector<int>>&adj, vector<bool>&vis , int u , int par , int n , vector<int>&dt, vector<int>&low ){
          vis[u]= true ;
          dt[u] = low[u] = ++time ;

          for( auto &v: adj[u]){
            if(!vis[v]){
                tarjan(adj, vis, v, u,n,dt,low);
                low[u] = min(low[u],low[v]);
                if (dt[u]< low[v]){
                    ans.push_back({u,v});
                }
            }
            else if(vis[u] && v!= par){
                low[u]= min(low[u],dt[v]);
            }
          }  
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_map<int , vector<int>>adj ;

        for( int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool>vis(n,false);
        vector<int>dt(n,INT_MAX);
        vector<int>low(n,INT_MAX);

        tarjan(adj,vis, 0,-1,n , dt , low);
        return ans ;

    }
};