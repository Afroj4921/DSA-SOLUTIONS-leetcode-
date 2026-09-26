class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        string result = "";
        unordered_map<string, string> mpp;
        for(const auto& kv : knowledge){
            mpp[kv[0]] = kv[1];
        }

        int i=0;
        while(i < n){
            if(s[i] == '('){
                i++;
                string temp = "";
                while(i<n &&s[i] != ')'){
                    temp.push_back(s[i]);
                    i++;
                }
                result += mpp.count(temp) ? mpp[temp] : "?";
                i++;
            }else{
                result.push_back(s[i]);
                i++;
            }
        }
        return result;
    }
};