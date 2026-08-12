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
        vector<int> after(T+1, 0), curr(T+1, 0);

        for(int ind=n-1; ind>=0; ind--){
            for(int trans=T-1; trans>=0; trans--){
                if(trans % 2 == 0){
                    curr[trans] = max(-prices[ind] + after[trans+1], 0 + after[trans]);
                } else{
                    curr[trans] = max(prices[ind] + after[trans+1], 0+ after[trans]);
                }
            }
            after = curr;
        }
        return after[0];
    }
};