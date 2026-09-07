class Solution {
public:
    int M = 1e9 + 7;
    // recursion and memoization
    int f(int n, vector<int> &prev, vector<int>& dp){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        int total = (2*f(n-1, prev, dp)) % M;

        if(prev[n] != 0){
            int duplicate = f(prev[n] - 1, prev, dp);
            total = (total - duplicate + M) % M;
        }

        return dp[n] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> prev(n+1, 0);
        vector<int> lastseen(26, 0);
        for(int i=1; i<=n; i++){
            int idx = s[i-1] -'a';
            prev[i] = lastseen[idx];
            lastseen[idx] = i;
        }
        vector<int> dp(n+1, -1);

        dp[0] = 1;
        for(int i=1; i<=n; i++){
            int total = (2* dp[i-1]) % M;

            if(prev[i] != 0){
                int duplicate = dp[prev[i] - 1];
                total = (total - duplicate + M) % M;
            }

            dp[i] = total;
        }
        return (dp[n] - 1 + M) % M;
    }
};