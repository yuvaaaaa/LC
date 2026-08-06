class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj , vector<int>&col , int u , int curr ){
        col[u] = curr ;

        for(auto &it: adj[u]){
            if(col[it]==col[u]){
                return false;
            }
            if(col[it]==-1){
                if(dfs(adj,col,it,1-curr)== false){
                    return false ;
                }
            }
        }
        return true ;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>col(n+1,-1);

        unordered_map<int,vector<int>>adj ;

        for(auto &it: dislikes){
            adj[it[0]].push_back({it[1]});
            adj[it[1]].push_back({it[0]});
        }

        for( int i=0;i<=n;i++){
            if(col[i]==-1){
                 if(dfs(adj,col,i,1) == false){
                    return false ;
                } 
            }
        }
        return true;

    }
};