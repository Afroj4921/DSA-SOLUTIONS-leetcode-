class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt = 0;
        for(int& num : nums){
            if(num < target){
                cnt++;
            }
        }

        vector<int> ans;
        for(int& num : nums){
            if(num == target){
                ans.push_back(cnt);
                cnt++;
            }
        }

        return ans;
    }
};