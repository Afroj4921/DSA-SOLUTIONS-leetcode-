class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int minEle = INT_MAX;

        for(int i=0; i<n; i++){
            sum += nums[i];
            minEle = min(minEle, nums[i]);
        }

        return sum-n*minEle;
    }
};