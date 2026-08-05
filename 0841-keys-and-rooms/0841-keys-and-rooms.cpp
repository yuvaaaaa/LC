class Solution {
public:
    void dfs(vector<vector<int>>& rooms , vector<bool>&visited, int u){
        
        for(int i=0;i< rooms[u].size();i++){
            if(visited[rooms[u][i]]== false){
            visited[rooms[u][i]] = true ;
                dfs(rooms,visited , rooms[u][i]);
            }
        }
        return ;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n =rooms.size();

        vector<bool>visited(n,false);
        visited[0] = true ;
        dfs(rooms,visited , 0);

        for(int i=0;i<n;i++){
            if(visited[i]==false) return false ;
        }

        return true ;
    }
};