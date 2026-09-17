class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return false;
        unordered_map<int, int> mpp;

        for(int i=0; i<n-1; i++){
            int sum = nums[i] + nums[i+1];
            if(mpp[sum] > 0) return true;
            mpp[sum]++;
        }
        return false;
    }
};