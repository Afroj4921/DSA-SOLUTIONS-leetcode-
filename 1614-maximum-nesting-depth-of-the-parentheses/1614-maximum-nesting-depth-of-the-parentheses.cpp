class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt = 1; 
        int ans = 0;
        stack<int> st;
        for(char& ch : s){
            if(ch == '('){
                st.push(cnt);
                ans = max(ans, cnt);
                cnt++;
            }else if(ch == ')'){
                st.pop();
                cnt--;
            }else{
                continue;
            }
        }
        return ans;
    }
};