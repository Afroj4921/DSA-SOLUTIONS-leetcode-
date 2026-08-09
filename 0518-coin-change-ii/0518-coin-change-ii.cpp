class Solution {
public:
    int f(int ind, int T, vector<int>& coins){
        if(ind == 0){
            return (T%coins[0] == 0); 
        }

        int notTake = f(ind-1, T, coins);
        int take = 0;
        if(coins[ind] <= T) take = f(ind, T-coins[ind], coins);

        return take +notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<double>> dp(n, vector<double> (amount+1, 0));

        for(int T=0; T<=amount; T++) dp[0][T] = (T%coins[0] == 0);

        for(int ind=1; ind<n; ind++){
            for(int T=0; T<=amount; T++){
                double notTake = dp[ind-1][T];
                double take = 0;
                if(coins[ind] <= T) take = dp[ind][T-coins[ind]];
                
                dp[ind][T]  = take + notTake;
            }
        }

        return (int)dp[n-1][amount];
    }
};