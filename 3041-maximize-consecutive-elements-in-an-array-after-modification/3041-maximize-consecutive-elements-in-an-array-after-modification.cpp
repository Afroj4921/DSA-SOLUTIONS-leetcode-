class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();
        if (j < n && nums[j] == target)
            return j;

        return -1;
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        dp.assign(n + 1, vector<int>(2, 0));

        int result = 1;


        for (int i = n - 1; i >= 0; i--) { //O(n * log(n))
            for (int inc = 0; inc <= 1; inc++) {

                int currVal = nums[i] + inc;
                int len = 1;

                //1st Option = find (currVal+1)
                int j = findMethod(nums, i + 1, currVal + 1);
                if (j != -1) {
                    len = max(len, 1 + dp[j][0]);
                }

                //2nd Option = find (currVal) and then inc by +1
                j = findMethod(nums, i + 1, currVal);
                if (j != -1) {
                    len = max(len, 1 + dp[j][1]);
                }

                dp[i][inc] = len;
                result = max(result, len);
            }
        }

        return result;
    }
};