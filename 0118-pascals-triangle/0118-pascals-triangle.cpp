class Solution {
public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row;
        int val = 1;
        row.push_back(val);
        for(int k=1; k<n; k++){
            val = val*(n-k)/k;
            row.push_back(val);
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i=1; i<=numRows; i++){
            triangle.push_back(nthRowOfPascalTriangle(i));
        }
        return triangle;
    }
};