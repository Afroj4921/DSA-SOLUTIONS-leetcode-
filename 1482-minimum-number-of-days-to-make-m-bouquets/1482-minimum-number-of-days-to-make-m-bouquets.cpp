class Solution {
public:
    bool possible(vector<int>& nums, int day, int m, int k){
        int cnt = 0, noB = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= day){
                cnt++;
            }else{
                noB += cnt/k;
                cnt = 0;
            }
        }
        noB += cnt/k;
        if(noB >= m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1LL*k*1LL;
        if(val > bloomDay.size()) return -1;
         int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};