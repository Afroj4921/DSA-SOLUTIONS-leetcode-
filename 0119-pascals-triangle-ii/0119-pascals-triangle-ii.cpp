class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> row;
        long long val = 1;
        row.push_back(val);
        for(int k=1; k<=n; k++){
            val = val*(n-k+1)/k;
            row.push_back(val);
        }
        return row;
    }
};