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
        vector<double> prev(amount+1, 0), curr(amount+1, 0);

        for(int T=0; T<=amount; T++) prev[T] = (T%coins[0] == 0);

        for(int ind=1; ind<n; ind++){
            for(int T=0; T<=amount; T++){
                double notTake = prev[T];
                double take = 0;
                if(coins[ind] <= T) take = curr[T-coins[ind]];
                
                curr[T]  = take + notTake;
            }
            prev = curr;
        }

        return (int)prev[amount];
    }
};