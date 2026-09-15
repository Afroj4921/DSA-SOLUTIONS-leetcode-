class Solution {
public:
    // Reccursion and memoization
    int f(string& s, int k, int i, int j, vector<vector<int>>& dp, vector<vector<bool>>& isPalindrome){
        int n = s.size();
        if(i >= n || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(isPalindrome[i][j]){
            int take = 1 + f(s, k, j+1, j+k, dp, isPalindrome);
            int grow = f(s, k, i, j+1, dp, isPalindrome);
            int slide = f(s, k, i+1, j+1, dp, isPalindrome);
            return dp[i][j] = max({take, grow, slide});
        }
        int grow = f(s, k, i, j+1, dp, isPalindrome);
        int slide = f(s, k, i+1, j+1, dp,isPalindrome);

        return dp[i][j] = max(grow, slide);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k == 1) return n;

        // isPalindrome blue Print
        vector<vector<bool>> isPalindrome(n+1, vector<bool> (n+1, false));

        for(int l=1; l<=n; l++){
            for(int i=0; i+l<=n; i++){
                int j = i+l-1;

                if(i == j){
                    isPalindrome[i][j] = true;
                }else if(i+1 == j){
                    isPalindrome[i][j] = (s[i] == s[j]);
                }else{
                    isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i+1][j-1];
                }
            }
        }

        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(isPalindrome[i][j]){
                    int take = 1 + (j+k <= n ? dp[j+1][j+k] : 0 );
                    int grow = dp[i][j+1];
                    int slide = dp[i+1][j+1];
                    dp[i][j] = max({take, grow, slide});
                }
                int grow = dp[i][j+1];
                int slide = dp[i+1][j+1];

                dp[i][j] = max({dp[i][j], grow, slide});
            }
        }
        return dp[0][k-1];
    }
};