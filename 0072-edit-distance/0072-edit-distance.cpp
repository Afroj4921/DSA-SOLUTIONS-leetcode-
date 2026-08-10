class Solution {
public:
    // recurrsion and mamoization
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]) return dp[i][j] =  f(i-1, j-1, s1, s2, dp);
        return dp[i][j] = 1 + min(f(i, j-1, s1, s2, dp), 
                            min(f(i-1, j, s1, s2, dp), f(i-1, j-1, s1, s2, dp)));

    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j=0; j<=m; j++) prev[j] = j;

        for(int i=1; i<=n; i++){
            curr[0] = i;
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) curr[j] =  prev[j-1];
                else curr[j] = 1 + min(prev[j], min(curr[j-1], prev[j-1]));
            }
            prev = curr;
        }

        return prev[m];
    }
};