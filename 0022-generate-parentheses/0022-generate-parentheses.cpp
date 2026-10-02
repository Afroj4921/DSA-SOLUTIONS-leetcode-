class Solution {
public:
    void f(string& curr, int n, vector<string>& ans, int open, int close){
        if(curr.size() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            curr.push_back('(');
            f(curr, n, ans, open+1, close);
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            f(curr, n, ans, open, close+1);
            curr.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        f(curr, n, ans, 0, 0);

        return ans;
    }
};