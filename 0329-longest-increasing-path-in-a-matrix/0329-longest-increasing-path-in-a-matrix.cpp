class Solution {
public: 
    int ans = 0;
    int largest (vector<vector<int>>& matrix , vector<vector<int>>&dirs, int i,int j ,vector<vector<int>>&dp){
        
         if(dp[i][j] != 0){
            return dp[i][j];
         }

        int m = matrix.size();
        int n = matrix[0].size(); 

        int size =1;

        for( auto &dir: dirs){
            int x = dir[0] + i;
            int y = dir[1] + j;

            if(x>=m || x<0 || y>=n || y<0 ){
                continue ;
            }

            if(matrix[i][j]<matrix[x][y]){
                size = max (size , 1+largest(matrix , dirs ,x,y,dp ));

            }
        }
       
       return dp[i][j] = size ;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp (m, vector<int>(n,0));
        vector<vector<int>> dirs ={{-1,0},{1,0},{0,-1},{0,1}};

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                ans = max(ans ,largest(matrix,dirs,i,j,dp));
            }
        }
        return ans;
    }
};