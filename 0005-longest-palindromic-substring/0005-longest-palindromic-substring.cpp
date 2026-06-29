class Solution {
public:
    int start = 0;
    int maxLen = 1;
    void expand(string &s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            if(r-l+1 > maxLen){
                maxLen = r-l+1;
                start = l;
            }
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        if(s.empty()) return "";
        for(int i=0; i<s.size(); i++){
            expand(s, i, i);//odd length
            expand(s, i, i+1);//even length
        }
        return s.substr(start, maxLen);
    }
};