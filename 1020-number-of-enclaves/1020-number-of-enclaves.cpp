class Solution {
public:
    void bfs(vector<vector<int>>& grid , vector<pair<int , int>> &dir , int i , int j){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q ;
        q.push({i,j});
        grid[i][j]  = 0 ;

        while(!q.empty()){
            int u = q.front().first ;
            int v = q.front().second ;
            q.pop();
            
            for( auto &it: dir){
                int x = u+ it.first ;
                int y = v +it.second ;

                if(x >= m || x<0 || y>=n || y<0 ){
                    continue ;
                }
                if(grid[x][y]==1){
                    q.push({x,y});
                    grid[x][y] = 0;
                }
            }
        }
        return ;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int , int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i< n;i++){
            if(grid[0][i]==1 ){
                bfs(grid, dir , 0 , i );
            }
        }
        for(int i=0;i< m;i++){
            if(grid[i][0]==1  ){
                bfs(grid, dir , i , 0 );
            }
        }
        for(int i=0;i< n;i++){
            if(grid[m-1][i]==1 ){
                bfs(grid, dir , m-1 , i );
            }
        }
        for(int i=0;i< m;i++){
            if(grid[i][n-1]==1 ){
                bfs(grid, dir , i , n-1 );
            }
        }
        int count =0;
        for( int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( grid[i][j] == 1 ){
                    count ++ ;
                }
            }
        }
        return count;
    }
};