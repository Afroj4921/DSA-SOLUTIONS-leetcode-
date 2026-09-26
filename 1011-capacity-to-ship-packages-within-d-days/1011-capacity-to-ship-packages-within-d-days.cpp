class Solution {
public:
    int findDays(vector<int>& weights, int mid){
        int days = 1, load = 0;
        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] > mid){
                days += 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = INT_MIN;
        int ans = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }

        int low = maxi, high = sum;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(findDays(weights, mid) <= days){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};