class Solution {
public:
    // recurssion and memoization
    int f(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(ind == n) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        int len = 0 + f(ind+1, prev_ind, nums, n, dp);
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len, 1 + f(ind+1, ind, nums, n, dp));
        }
        return dp[ind][prev_ind+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            } else{
                auto ind = lower_bound(temp.begin(), temp.end(), nums[i]);
                *ind = nums[i];
            }
        }
        return len;
    }
};