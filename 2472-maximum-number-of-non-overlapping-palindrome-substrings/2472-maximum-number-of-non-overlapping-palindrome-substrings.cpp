class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }

    int f(string& s, int k, int i, int j, vector<vector<int>>& dp){
        int n = s.size();
        if(i >= n || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(isPalindrome(s, i, j)){
            int take = 1 + f(s, k, j+1, j+k, dp);
            int grow = f(s, k, i, j+1, dp);
            int slide = f(s, k, i+1, j+1, dp);
            return dp[i][j] = max({take, grow, slide});
        }
        int grow = f(s, k, i, j+1, dp);
        int slide = f(s, k, i+1, j+1, dp);

        return dp[i][j] = max(grow, slide);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k == 1) return n;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return f(s, k, 0, k-1, dp);
    }
};