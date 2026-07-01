class Solution {
public:
    void lpsFind(vector<int>& lps, string needle){
        int pre = 0, suf = 1;
        while(suf < needle.size()){
            if(needle[pre] == needle[suf]){
                lps[suf] = pre + 1;
                pre ++;
                suf ++;
            }else{
                if(pre == 0){
                    lps[suf] = 0;
                    suf++;
                }else{
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        lpsFind(lps, needle);
        int first = 0, second = 0;
        while(first < haystack.size() && second < needle.size()){
            // match
            if(haystack[first] == needle[second]){
                first++;
                second++;
            } else{
                if(second == 0){
                    first++;
                }else{
                    second = lps[second - 1];
                }
            }
        }
        if(second == needle.size()){
            return first - second;
        }
        return -1;
    }
};