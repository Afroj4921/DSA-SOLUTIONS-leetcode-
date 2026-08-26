class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int ones = 0;
        string result = "";
        while(j < n){
            if(s[j] == '1'){
                ones++;
            }
            while(ones > k || s[i] == '0'){
                if(s[i] == '1'){
                    ones--;
                }
                i++;
            }
            if(ones == k){
                string temp = s.substr(i, j-i+1);
                if(result.empty() || result.size() > j-i+1 ||
                    (temp.size() == result.size() && temp < result)){
                    result = temp;
                }
            }
            j++;
        }
        return result;
    }
};