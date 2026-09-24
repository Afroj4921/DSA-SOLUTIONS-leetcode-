class Solution {
public:
    int sumOfDig(vector<int>& nums, int i){
        int sum = 0;
        int val = nums[i];
        while(val > 0){
            sum += val%10;
            val = val/10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(sumOfDig(nums, i) == i){
                return i;
            }
        }
        return -1;
    }
};