class Solution {
public:
    bool f(string& s, int idx, int cnt, int n, vector<vector<int>>& dp){
        if(cnt < 0) return false;
        if(idx == n) return (cnt == 0);

        if(dp[idx][cnt] != -1) return dp[idx][cnt];

        if(s[idx] == '('){
           return dp[idx][cnt] = f(s, idx+1, cnt+1, n, dp);
        }
        if(s[idx] == ')'){
           return dp[idx][cnt] = f(s, idx+1, cnt-1, n, dp);
        }
        return dp[idx][cnt] = (f(s, idx+1, cnt+1, n, dp) || f(s, idx+1, cnt-1, n, dp) || f(s, idx+1, cnt, n, dp));
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(s, 0, 0, n, dp);
    }
};