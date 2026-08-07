class Solution {
public:
    vector<int>ans ;
    int search(vector<int>&par , int i ){
        if(par[i]== i){
            return i ;
        }
        int a = search(par, par[i]);
        par[i] = a ;
        return a ;
    }
    void uni(vector<int>&par , int i , int j , vector<int>&rank ){
        int pi = search(par, i);
        int pj = search(par, j);

        if(pi == pj) {
            ans.clear();
            ans = {i,j};
        }

        if(rank[pi]==rank[pj]){
            par[pi]=pj;
            rank[pj]++ ;

        }
        else if(rank[pj]> rank[pi]){
            par[pi] = pj;
        }
        else{
            par[pj] = pi;
        }
        return ;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>par(n+1);
        for(int i=0;i<par.size();i++){
            par[i] = i;
        }
        vector<int>rank(n+1 , 0);
        for(int i=0 ;i<edges.size();i++){
            uni(par ,edges[i][0],edges[i][1], rank );
        }

        return ans ;
    }
};