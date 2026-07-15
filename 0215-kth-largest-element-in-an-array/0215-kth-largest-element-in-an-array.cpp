class Solution {
public:
    int partition(vector<int>& nums, int L,int R){
        int p = nums[L];
        int i = L+1;
        int j = R;
        
        while(i <= j){
            if(nums[i] < p && nums[j] > p){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i] >= p){
                i++;
            }
            if(nums[j] <= p){
                j--;
            }
        }
        swap(nums[L], nums[j]);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        int L = 0;
        int R = n-1;
        int pivot = 0;
        while(true){
            pivot = partition(nums, L, R);
            if(pivot == k-1){
                break;
            } else if(pivot > k-1){
                R = pivot - 1;
            } else{
                L = pivot + 1;
            }
        }
        return nums[pivot];
    }
};