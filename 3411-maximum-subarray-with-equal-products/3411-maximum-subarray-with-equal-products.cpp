class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        int ans = 2; 
        int left = 0;
        long long prod = 1;
        
        for (int right = 0; right < n; ++right) {
            while (gcd(prod, (long long)nums[right]) > 1) {
                prod /= nums[left];
                left++;
            }
            
            prod *= nums[right];
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};