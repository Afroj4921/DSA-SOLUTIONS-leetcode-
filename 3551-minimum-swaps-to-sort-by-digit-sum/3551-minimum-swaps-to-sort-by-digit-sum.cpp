class Solution {
public:
    int getDigSum(int num){
        int sum = 0;
        while(num > 0){
            sum += (num%10);
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSort(nums);

        auto lambda = [&](int num1, int num2){
            int n1DigSum = getDigSum(num1);
            int n2DigSum = getDigSum(num2);

            if(n1DigSum != n2DigSum){
                return n1DigSum < n2DigSum;
            }

            return num1 < num2;
        };

        sort(afterSort.begin(), afterSort.end(), lambda);

        unordered_map<int, int> valToIdx;
        for(int i=0; i<n; i++){
            valToIdx[nums[i]] = i;
        }

        int swapCnt = 0;
        for(int i=0; i<n; i++){
            int expectedVal = afterSort[i];
            int currVal = nums[i];

            if(expectedVal == currVal) continue;

            int idx = valToIdx[expectedVal];
            

            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;

            swapCnt++;
        }

        return swapCnt;

    }
};