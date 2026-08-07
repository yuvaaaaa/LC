class Solution {
public:
    int count =0;
    int search(vector<int>&par , int i ){
        if(par[i]==i){
            return i;
        }

        int a = search(par, par[i]);
        par[i] = a;
        return a ;

    }
    void uni(vector<int>&par , vector<int>&rank , int i , int j){

        int pi = search(par ,i);
        int pj = search(par ,j);

        if(pi == pj ){
            count ++ ;
            return ;
        }
        if(rank[pi]== rank[pj]){
            par[pi] = pj ;
            rank[pj]++ ;
        }
        else if(rank[pi]> rank[pj]){
            par[pj] = pi;
        }
        else{
            par[pi] = pj;
        }
        return ;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>par(n);

        for(int i=0;i<n;i++){
            par[i] =i;
        }
        vector<int>rank(n,0);

        for(int i =0;i<connections.size();i++){
            uni(par,rank,connections[i][0],connections[i][1]);
        }
        unordered_set<int>st ;
        for(int i=0;i<n;i++){
            st.insert(search(par , par[i]));
        }

        int d = st.size();
        if(count>= d-1) return d-1;

        return -1 ;
    }
};