class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            mpp[sum] = i;
        }
        if(sum < x) return -1;

        int remainSum = sum - x;
        int longestArrSum = INT_MIN;
        sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int findSum = sum-remainSum;

            if(mpp.find(findSum) != mpp.end()){
                int idx = mpp[findSum];
                longestArrSum = max(longestArrSum, i-idx);
            }
        }
        return longestArrSum == INT_MIN ? -1 : n-longestArrSum;
    }
};