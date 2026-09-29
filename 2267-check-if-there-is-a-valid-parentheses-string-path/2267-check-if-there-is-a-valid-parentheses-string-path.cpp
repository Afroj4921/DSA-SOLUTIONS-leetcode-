class Solution {
public:
    bool f(int i, int j, int openCnt, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        openCnt += (grid[i][j] == '(') ? 1 : -1;

        if(openCnt < 0) return false;

        if(dp[i][j][openCnt] != -1) 
            return dp[i][j][openCnt];
        

        if(i == m-1 && j == n-1)
            return dp[i][j][openCnt] = (openCnt == 0);

        if(i+1 < m){
            if(f(i+1, j, openCnt, grid, dp)) 
                return dp[i][j][openCnt] = true;
        }

        if(j+1 < n){
            if(f(i, j+1, openCnt, grid, dp)) 
                return dp[i][j][openCnt] = true;
        }

        return dp[i][j][openCnt] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if((m+n-1)%2 == 1) return false;

        if(grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int> (m+n, -1)));

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                for(int openCnt=0; openCnt<=i+j+1; openCnt++){
                    if(i == m-1 && j == n-1){
                        dp[i][j][openCnt] = (openCnt == 0);
                        continue;
                    }
                    dp[i][j][openCnt] = false;

                    if(i+1 < m){
                        int newOpCnt = (grid[i+1][j]) == '(' ? openCnt+1 : openCnt-1;
                        if(newOpCnt >= 0 && dp[i+1][j][newOpCnt] == true)
                            dp[i][j][openCnt] = true;
                    }
                    if(j+1 < n){
                        int newOpCnt = (grid[i][j+1]) == '(' ? openCnt+1 : openCnt-1;
                        if(newOpCnt >= 0 && dp[i][j+1][newOpCnt] == true)
                            dp[i][j][openCnt] = true;
                    }
                }
            }
        }

        return dp[0][0][1];
    }
};