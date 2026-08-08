class Solution {
public:
    int search(vector<int>&par , int  i){
        if(par[i] == i) return i;

        return par[i] = search(par,par[i]);
    }

    void uni(vector<int>&par , vector<int>&rank , int i , int j){

        int pi = search(par, i);
        int pj = search(par, j);

        if(pi == pj) return ;

        if(rank[pi]== rank[pj]){
            par[pj]=pi;
            rank[pi]++ ;
        }
        else if (rank[pi]>rank[pj]){
            par[pj] =pi ;
        }
        else {
            par[pi]=pj;
        }
        return ;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n = s.size();
        vector<int>par(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }

        vector<int>rank(n,0);

        for( int i=0;i< pairs.size();i++){
            uni(par,rank, pairs[i][0] , pairs[i][1]);
        }

        for(int i =0;i< n;i++){
           par[i] = search(par, par[i]);
        }

        unordered_map<int, vector<char>> mp;

        for(int i = 0; i < n; i++) {
            mp[par[i]].push_back(s[i]);
        }

        for(auto &it : mp) {
            sort(it.second.begin(), it.second.end());
        }

        unordered_map<int, int> index;
        string ans = "";

        for(int i = 0; i < n; i++) {

            int root = par[i];
            ans.push_back(mp[root][index[root]]);
            index[root]++;
        }

        return ans;
    }
};