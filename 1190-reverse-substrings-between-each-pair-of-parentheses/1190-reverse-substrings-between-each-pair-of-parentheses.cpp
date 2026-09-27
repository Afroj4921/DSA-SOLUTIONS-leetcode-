class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> skipStr;
        string result = "";

        for(char& ch : s){
            if(ch == '('){
                skipStr.push(result.size());
            }else if(ch == ')'){
                int l = skipStr.top();
                skipStr.pop();
                reverse(result.begin()+l, result.end());
            }else{
                result.push_back(ch);
            }
        }
        return result;
    }
};