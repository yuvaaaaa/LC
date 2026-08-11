class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int,int>> dir={ {-1,0},{1,0},{0,1},{0,-1}} ;

        queue<pair<int,int>>q ;

        for( int i=0 ;i<m ;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=INT_MAX ;
            }
        }

        while(!q.empty()){

            int u = q.front().first ;
            int v = q.front().second ;
            q.pop();
            for(auto &it: dir){

                int r = u+ it.first ;
                int s = v + it.second ;

                if(r>=m || r<0 || s>= n ||s<0 ) continue ;

                else if(mat[u][v] + 1 < mat[r][s]){
                    mat[r][s] = mat[u][v] + 1 ;
                    q.push({r , s });
                }

            }
        }
        return mat ;

    }
};