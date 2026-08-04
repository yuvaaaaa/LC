class Solution {
public:

    void dfs (vector<bool>&visited , int u , vector<vector<int>>& isConnected ){

        int n = isConnected.size();

        for(int i=0;i<n;i++){
            if(isConnected[u][i]==1 && visited[i] == false){
                visited[i] = true ;
                dfs(visited , i, isConnected);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<bool>visited(n,false);
        int count =0;

        for(int i=0;i<n;i++){
            if(visited[i]== false){
                visited[i] = true ;
                dfs(visited , i,isConnected);
                count ++ ;
            }
        }
        return count;
    }
};