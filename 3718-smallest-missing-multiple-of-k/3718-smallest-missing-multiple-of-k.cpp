class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int mul = k;
        while(num_set.count(mul)){
            mul += k;
        }
        return mul;
    }
};