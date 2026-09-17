class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int res = nums[0];
        int minProd = nums[0];
        int maxProd = nums[0];

        for(int i=1; i<n; i++){
            int curr = nums[i];
            if(curr < 0) swap(minProd, maxProd);
            
            maxProd = max(curr, maxProd*curr);
            minProd = min(curr, minProd*curr);
            res = max(res, maxProd);
        }
        return res;
    }
};