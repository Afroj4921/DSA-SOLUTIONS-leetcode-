class Solution {
public:
    // recurssion and memoization
    int f(int ind, int trans, vector<int>& prices, int n, int k, vector<vector<int>>& dp){
        if(ind == n || trans == k) return 0;
        if(dp[ind][trans] != -1) return dp[ind][trans];
        if(trans % 2 == 0){
            return dp[ind][trans] = max(-prices[ind] + f(ind+1, trans+1, prices, n, k, dp), 0 + f(ind+1, trans, prices, n, k, dp));
        } else{
            return dp[ind][trans] = max(prices[ind] + f(ind+1, trans+1, prices, n, k, dp), 0+ f(ind+1, trans, prices, n, k, dp));
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int T = 2*k;
        vector<vector<int>> dp(n+1, vector<int> (T+1, 0));

        for(int ind=n-1; ind>=0; ind--){
            for(int trans=0; trans<T; trans++){
                if(trans % 2 == 0){
                    dp[ind][trans] = max(-prices[ind] + dp[ind+1][trans+1], 0 + dp[ind+1][trans]);
                } else{
                    dp[ind][trans] = max(prices[ind] + dp[ind+1][trans+1], 0+ dp[ind+1][trans]);
                }
            }
        }
        return dp[0][0];
    }
};