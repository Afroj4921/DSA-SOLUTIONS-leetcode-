class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newcolor, int orgColor){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] != orgColor ||
            image[i][j]==newcolor){
                return;
            }
            image[i][j] = newcolor;
            dfs(image, i-1, j, newcolor, orgColor);
            dfs(image, i, j+1, newcolor, orgColor);
            dfs(image, i+1, j, newcolor, orgColor);
            dfs(image, i, j-1, newcolor, orgColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};