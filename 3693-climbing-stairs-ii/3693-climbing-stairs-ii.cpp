class Solution {
public:
    int helper(int i, int n, vector<int>& costs, vector<int>& memo){
        if(i == n) return 0;

        if(memo[i] != -1) return memo[i];

        int cost = INT_MAX;

        int j = i+1;//one step
        if(j<=n){
            cost = helper(j, n, costs, memo) + costs[j-1] + (j-i)*(j-i);
        }
        
        j = i+2;//two steps
        if(j<=n){
            cost = min(cost, helper(j, n, costs, memo) + costs[j-1] + (j-i)*(j-i));
        }
        
        j = i+3;//three steps
        if(j<=n){
            cost = min(cost, helper(j, n, costs, memo) + costs[j-1] + (j-i)*(j-i));
        }

        return memo[i] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--){
            int cost = INT_MAX;

            int j = i+1;//one step
            if(j<=n){
                cost = dp[j] + costs[j-1] + (j-i)*(j-i);
            }
            
            j = i+2;//two steps
            if(j<=n){
                cost = min(cost, dp[j] + costs[j-1] + (j-i)*(j-i));
            }
            
            j = i+3;//three steps
            if(j<=n){
                cost = min(cost, dp[j] + costs[j-1] + (j-i)*(j-i));
            }
            dp[i] = cost;
        }
        return dp[0];
    }
};