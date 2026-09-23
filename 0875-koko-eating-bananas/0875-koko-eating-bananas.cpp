class Solution {
public:
    long long sumByD(vector<int>& nums, int div){
        long long sum =0;
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i]+div-1)/div;
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low<= high){
            int mid= low + (high-low)/2;
            if(sumByD(piles, mid) <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};