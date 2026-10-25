class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i>=m || i<0 || j>=n || j<0){
            return false;
        }

        if(grid[i][j] == 1) return true;

        grid[i][j] = 1;

        bool left = dfs(grid, i, j-1, n, m);
        bool right = dfs(grid, i, j+1, n, m);
        bool up = dfs(grid, i-1, j, n, m);
        bool down = dfs(grid, i+1, j, n, m);

        return left && right && up && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    cnt += dfs(grid, i, j, n, m);
                }
            }
        }

        return cnt;
    }
};