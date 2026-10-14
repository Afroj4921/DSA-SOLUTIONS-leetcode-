class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) {
            return "";
        }

        int nines = sum / 9;
        int rem = sum % 9;

        string ans(nines, '9');

        if (rem > 0) {
            ans.push_back(rem + '0');
        }

        ans.append(num - ans.size(), '0');

        return ans;
    }
};