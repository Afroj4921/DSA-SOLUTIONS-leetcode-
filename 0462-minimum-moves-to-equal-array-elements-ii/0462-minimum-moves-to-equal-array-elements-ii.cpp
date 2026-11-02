class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;

        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int cnt = 0;
        for(int num : nums){
            cnt += abs(num - nums[mid]);
        }
        return cnt;
    }
};