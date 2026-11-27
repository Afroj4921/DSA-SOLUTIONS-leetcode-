class Solution {
public:
    int t[1001][1501];


    int solve(int n, int budget, int minPrice, vector<vector<int>>& items, vector<int>& copies){
        if(n == 0){
            return budget/minPrice;
        }

        if(t[n][budget] != -1) return t[n][budget];

        int take = 0;
        int price = items[n-1][1];

        if(items[n-1][1] <= budget){
            take = 1 + copies[n-1] + solve(n-1, budget-price, minPrice, items, copies);
        }

        int skip = 0 + solve(n-1, budget, minPrice, items, copies);

        return t[n][budget] = max(take, skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> copies(n, 0);
        int minPrice = INT_MAX;

        for(int i=0; i<n; i++){
            int copy = 0;
            minPrice = min(minPrice, items[i][1]);
            for(int j=0; j<n; j++){
                if(i == j) continue;

                if(items[j][0] % items[i][0] == 0)
                    copy++;

            }
            copies[i] = copy;
        }

        vector<vector<int>> dp(n+1, vector<int>(budget + 1, 0));

        for(int b=0; b<=budget; b++){
            dp[0][b] = b/minPrice;
        }

        for(int i=1; i<=n; i++){
            for(int b=0; b<=budget; b++){
                int take = 0;
                int price = items[i-1][1];

                if(price <= b){
                    take = 1 + copies[i-1] + dp[i-1][b - price];
                }

                int skip = 0 + dp[i-1][b];

                dp[i][b] = max(take, skip);
            }
        }

        return dp[n][budget];
    }
};