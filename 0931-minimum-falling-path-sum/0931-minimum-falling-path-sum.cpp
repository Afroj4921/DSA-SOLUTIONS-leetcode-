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
                int s = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                if(j-1 >= 0){
                    ld += prev[j-1];
                } else{
                    ld += 1e9;
                }

                int rd = matrix[i][j];
                if(j+1 < n){
                    rd += prev[j+1];
                } else{
                    rd += 1e9;
                }

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