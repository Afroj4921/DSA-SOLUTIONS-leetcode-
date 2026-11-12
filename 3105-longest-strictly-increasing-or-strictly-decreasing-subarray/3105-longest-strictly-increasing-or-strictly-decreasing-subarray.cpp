class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int inc = 1;
        int decr = 1;

        int result = 1;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                inc++;
                decr = 1;
                result = max(result, inc);
            }else if(nums[i] < nums[i-1]){
                decr++;
                inc = 1;
                result = max(result, decr);
            }else{
                inc = 1;
                decr = 1;
            }
        }
        return result;
    }

};