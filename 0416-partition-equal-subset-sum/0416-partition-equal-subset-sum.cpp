class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum+1, 0), curr(sum+1, 0);
        
        prev[0] = curr[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;
        
        for(int ind=1; ind<n; ind++){
            for(int tar=1; tar<=sum; tar++){
                bool notTake = prev[tar];
                bool take = false;
                if(arr[ind] <= tar) take = prev[tar-arr[ind]];
                curr[tar] = notTake | take;
            }
            prev = curr;
        }
        return prev[sum];
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for(int i=0; i<n; i++) totsum += nums[i];     
        if(totsum % 2) return false;
        int tar = totsum/2;
        return isSubsetSum(nums, tar);
    }
};