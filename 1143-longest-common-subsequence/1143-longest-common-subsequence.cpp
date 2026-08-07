class Solution {
public:
    // recursion + memoization
    int f(int i, int j, string& s1, string s2, vector<vector<int>>& dp){
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]) return 1 + f(i-1, j-1, s1, s2, dp);

        return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j=0; j<=m; j++) prev[j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1]) curr[j] =  1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[m];
    }
};