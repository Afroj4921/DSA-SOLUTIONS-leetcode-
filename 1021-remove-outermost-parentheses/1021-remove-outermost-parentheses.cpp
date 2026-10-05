class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        
        for(char ch : s){
            if(ch == '('){
                if(cnt > 0){
                    ans.push_back(ch);
                }
                cnt++;
            }else{
                cnt--;
                if(cnt > 0){
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};