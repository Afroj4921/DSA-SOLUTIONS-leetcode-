class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> miss;
        int num = 1;
        int i=0;
        while(miss.size() < k){
            if(i < n && arr[i] == num){
                i++;
            }else{
                miss.push_back(num);
            }
            num++;
        }
        return miss[k-1];
    }
};