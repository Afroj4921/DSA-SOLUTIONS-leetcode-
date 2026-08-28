class Solution {
public:
    char midChar = '$';
    int halfLen = 0;
    string result = "";

    bool solve(string curr, vector<int>& count, string target, int i, bool greater){
        if(curr.size() == halfLen){
            string candidate = curr; //left half
            string rightHalf = curr;
            reverse(rightHalf.begin(), rightHalf.end()); //right half

            if(midChar != '$'){
                candidate += midChar;
            }
            candidate += rightHalf;
            if(candidate > target){
                result = candidate;
                return true;
            }
            return false;
        }
        for(char ch='a'; ch<='z'; ch++){
            if(count[ch-'a'] == 0)
                continue;
            
            if(greater == false && ch < target[i])
                continue;
            
            curr.push_back(ch);
            count[ch-'a']--;

            bool isGreater = greater || ch > target[i];
            if(solve(curr, count, target, i+1, isGreater))
                return true;
            
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);

        for(char &ch : s)
            count[ch - 'a']++;
        
        int oddCount = 0;
        for(int c=0; c<26; c++){
            if(count[c] % 2 == 1){
                oddCount++;
                midChar = c + 'a';
            }
        }
        if(oddCount > 1)
            return "";
        
        // for left half of palindrom
        for(int  c=0; c<26; c++){
            count[c] /= 2;
        }
        halfLen = n/2;
        string curr = "";
        solve(curr, count, target, 0, false);

        return result;
    }
};