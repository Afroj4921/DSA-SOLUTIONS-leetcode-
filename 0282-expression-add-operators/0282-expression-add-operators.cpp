class Solution {
public:
    void f(int idx, string num, string temp, vector<string>& ans, int target, long long prev, long long res){
        int n = num.size();
        if(idx == n){
            if(res == target){
                ans.push_back(temp);
            }
        }

        string st = "";
        long long curr = 0;
        for(int j=idx; j<n; j++){
            if(j > idx && num[idx] == '0'){
                break;
            }
            st += num[j];
            curr = curr*10 + (num[j] - '0');

            if(idx == 0){
                f(j+1, num, temp+st, ans, target, curr, curr);
            } else{
                f(j+1, num, temp+'+'+st, ans, target, curr, res+curr);
                f(j+1, num, temp+'-'+st, ans, target, -curr, res-curr);
                f(j+1, num, temp+'*'+st, ans, target, prev*curr, res-prev + prev*curr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string  temp = "";
        f(0, num, temp, ans, target, 0, 0);
        return ans;
    }
};