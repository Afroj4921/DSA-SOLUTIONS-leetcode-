class Solution {
public:
    // recurssion and memoiztion
    int f(int ind, int buy, int fee, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy] = max(-prices[ind] + f(ind+1, 0, fee, prices, n, dp), 0 + f(ind+1, 1, fee, prices, n, dp));
        }else{
            return dp[ind][buy] = max(prices[ind]- fee + f(ind+1, 1, fee, prices, n, dp), 0 + f(ind+1, 0, fee, prices, n, dp));
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> after(2, 0), curr(2, 0);

        for(int ind=n-1; ind>=0; ind--){
            curr[1] = max(-prices[ind] + after[0], 0 + after[1]);
            curr[0] = max(prices[ind]- fee + after[1], 0 + after[0]);
            after = curr;
        }
        return after[1];
    }
};