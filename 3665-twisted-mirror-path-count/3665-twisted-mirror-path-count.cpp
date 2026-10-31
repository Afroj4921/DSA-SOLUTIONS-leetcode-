class Solution {
public:
    int LEFT = 0;
    int UP = 1;
    int MOD = 1e9+7;
    int m;//rows
    int n;//cols

    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom, vector<vector<array<int, 2>>>& t){
        if(i >= m ||j >= n){
            return 0;
        }

        if(i == m-1 && j == n-1) return 1;

        if(t[i][j][cameFrom] != -1) {
            return t[i][j][cameFrom];
        }

        if(grid[i][j] == 1){
            if(cameFrom == LEFT){
                return t[i][j][cameFrom] = solve(grid, i+1, j, UP, t);
            } else{
                return t[i][j][cameFrom] = solve(grid, i, j+1, LEFT, t);
            }
        }

        int totalPathsCount = 0;
        totalPathsCount = (totalPathsCount + solve(grid, i, j+1, LEFT, t)) % MOD;
        totalPathsCount = (totalPathsCount + solve(grid, i+1, j, UP, t)) % MOD;

        return t[i][j][cameFrom] = totalPathsCount;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<array<int, 2>>> t(m+1,vector<array<int, 2>>(n+1, {0, 0}));


        for(int row=m-1; row>=0; row--){
            for(int col=n-1; col>=0; col--){
                for(int cameFrom=0; cameFrom<2; cameFrom++){
                    if(row == m-1 && col == n-1){
                        t[row][col][cameFrom] = 1;
                        continue;
                    }

                    if(grid[row][col] == 1){
                        if(cameFrom == LEFT){
                            t[row][col][cameFrom] = t[row + 1][col][UP];
                        }else{
                            t[row][col][cameFrom] = t[row][col + 1][LEFT];
                        }
                        continue;
                    }

                    long long total = 0;
                    total += t[row][col+1][LEFT];
                    total += t[row + 1][col][UP];

                    t[row][col][cameFrom] = total % MOD;
                }
            }
        }

        return t[0][0][LEFT];
    }
};