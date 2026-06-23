class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numsIndex;
        for (int i = 0; i < n; i++) {
            numsIndex.push_back({nums[i], i});
        }
        sort(numsIndex.begin(), numsIndex.end());
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numsIndex[left].first + numsIndex[right].first;
            if (sum == target) {
                return {numsIndex[left].second, numsIndex[right].second};
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return {-1, -1};
    }
};