class Solution {
public:
    void bfs (vector<vector<int>>& grid , queue<pair<int,int>>&q , int &count , int &ans ){
        
        int j = q.size() ;

        
        while(j--){

            
            pair<int,int> dummy = q.front();
            q.pop();
            int m = dummy.first ;
            int n = dummy.second ;
            if(m-1>=0 && grid[m-1][n]==1){
                q.push({m-1,n});
                count -- ;
                grid[m-1][n] =2;
            }
            if(m+1 < grid.size() && grid[m+1][n]==1){
                q.push({m+1,n});
                count -- ;
                grid[m+1][n] =2;
            }
             if(n-1>=0 && grid[m][n-1]==1){
                q.push({m,n-1});
                count -- ;
                grid[m][n-1] =2;
            }
             if(n+1 <grid[0].size() && grid[m][n+1]==1){
                q.push({m,n+1});
                count -- ;
                grid[m][n+1] =2;
            }
        }
        ans ++ ;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int ans = 0;
        queue<pair<int,int>>q ;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) count ++ ;
                else if(grid[i][j]==2){
                    q.push({i,j});
                } 
            }
        }

        if(count==0) return 0;

        while(!q.empty()&& count>0){
            bfs(grid,q,count,ans);
        }

        if(count>0) return -1 ;

        return ans;

    }
};