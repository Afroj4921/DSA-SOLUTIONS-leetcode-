class Solution {
public:
    int isValid(vector<int>& nums, int mid){
        int split = 1, maxSum = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxSum + nums[i] <= mid){
                maxSum += nums[i];
            }else{
                split++;
                maxSum = nums[i];
            }
        }
        return split;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }

        int low = maxi, high = sum;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isValid(nums, mid) <= k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};