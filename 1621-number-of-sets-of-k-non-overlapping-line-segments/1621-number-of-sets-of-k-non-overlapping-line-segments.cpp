class Solution {
public:
    int M = 1e9+7;
    int f(int n, int k, int i, vector<vector<int>>& dp){
        if(k == 0) return 1;
        if(i >= n) return 0;

        if(dp[k][i] != -1) return dp[i][k];

        long long start = 0;
        for(int j=i+1; j<n; j++){
            start = (start + f(n, k-1, j, dp)) % M;
        }
        long long notStart = f(n, k, i+1, dp) % M;

        return dp[k][i] = (notStart + start) % M; 
    }

    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k+1, vector<int> (n+1, 0));

        for(int i=0; i<n; i++){
            dp[0][i] = 1;
        }

        for(int K=1; K<=k; K++){

            vector<int> prevRow(n+1, 0);
            for(int x=n-1; x>=0; x--){
                prevRow[x] = (prevRow[x+1] + dp[K-1][x]) % M;
            }
            for(int i=n-1; i>=0; i--){
                long long start = prevRow[i+1];

                long long notStart = dp[K][i+1] % M;

                dp[K][i] = (notStart + start) % M;
            }
        }
        return dp[k][0] % M;
    }
};