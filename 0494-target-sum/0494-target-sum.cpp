class Solution {
public:
    int perfectSum(int n, vector<int>& arr, int target) {
        vector<int> prev(target+1, 0), curr(target+1, 0);
        if(arr[0] == 0){
            prev[0] = 2;
        }
        else{
            prev[0] = 1;
        
            if(arr[0] <= target)
                prev[arr[0]] = 1;
        }
        for(int ind=1; ind<n; ind++){
            for(int tar=0; tar<=target; tar++){
                int notPick = prev[tar];
                int pick = 0;
                if(arr[ind] <= tar) pick = prev[tar - arr[ind]];
        
                curr[tar] = pick + notPick;
            }
            prev = curr;
        }
        return prev[target];
    }
  
    int countPartitions(int n, vector<int>& arr, int diff) {
        int totSum = 0;
        for(int i=0; i<n; i++) totSum+= arr[i];
        if (totSum < diff || ((totSum - diff) % 2 != 0)) return 0;
        return perfectSum(n, arr, (totSum-diff)/2);
        
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, nums, target);
    }
};