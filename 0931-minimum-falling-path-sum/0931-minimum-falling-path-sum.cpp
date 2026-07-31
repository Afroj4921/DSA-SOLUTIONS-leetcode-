class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, -1);
        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                int ld = INT_MAX, rd = INT_MAX;
                int s = matrix[i][j] + prev[j];
                if(j-1 >= 0) ld = matrix[i][j] + prev[j-1];
                if(j+1 < n) rd = matrix[i][j] + prev[j+1];

                curr[j] = min({s, ld, rd});
            }
            prev = curr;
        }
        int minPath = prev[0];
        for(int j=1; j<n; j++){
            minPath = min(minPath, prev[j]);
        }
        return minPath;
    }
};