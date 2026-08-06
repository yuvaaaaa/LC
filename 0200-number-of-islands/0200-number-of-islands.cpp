class Solution {
public:
    bool isSafe(int m, int n, int x, int y) {
        if (x >= m || y >= n || x < 0 || y < 0) {
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n,
             vector<vector<int>> dir) {

        for (auto& it : dir) {
            int j = x + it[0];
            int k = y + it[1];
            if (isSafe(m, n, j, k) && grid[j][k] == '1'  ) {
                grid[j][k] = '0';
                dfs(grid, j, k, m, n, dir);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n, dir);
                    count++;
                }
            }
        }
        return count;
    }
};