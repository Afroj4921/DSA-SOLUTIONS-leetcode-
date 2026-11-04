
class Solution {
public:
    using ll = long long;

    multiset<int> low, high;
    ll sumLow = 0, sumHigh = 0;

    // Insert an element into the sliding window
    void add(int num) {
        if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
            sumLow += num;
        } else {
            high.insert(num);
            sumHigh += num;
        }

        balance();
    }

    // Remove an element from the sliding window
    void remove(int num) {
        auto it = low.find(num);

        if (it != low.end()) {
            sumLow -= num;
            low.erase(it);
        } else {
            it = high.find(num);
            sumHigh -= num;
            high.erase(it);
        }

        balance();
    }

    // Maintain the median in the lower half
    void balance() {
        while (low.size() > high.size() + 1) {
            int num = *low.rbegin();

            low.erase(prev(low.end()));
            sumLow -= num;

            high.insert(num);
            sumHigh += num;
        }

        while (low.size() < high.size()) {
            int num = *high.begin();

            high.erase(high.begin());
            sumHigh -= num;

            low.insert(num);
            sumLow += num;
        }
    }

    // Minimum cost to make the current window equal
    ll getCost() {
        ll median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int m = n - x + 1;

        vector<ll> cost(m);

        // Step 1: Calculate the cost of every window
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        for (int i = 0; i < m; i++) {
            cost[i] = getCost();

            if (i + x < n) {
                remove(nums[i]);
                add(nums[i + x]);
            }
        }

        // Step 2: Dynamic Programming
        const ll INF = 1e18;

        vector<vector<ll>> dp(
            m + 1,
            vector<ll>(k + 1, INF)
        );

        // Zero subarrays require zero operations
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {

                // Option 1: Skip the current window
                dp[i][j] = dp[i - 1][j];

                // Option 2: Select the current window
                if (j == 1) {
                    dp[i][j] = min(
                        dp[i][j],
                        cost[i - 1]
                    );
                } 
                else if (i >= x) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - 1]
                    );
                }
            }
        }

        return dp[m][k];
    }
};
