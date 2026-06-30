class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        while (i < n && isspace(s[i])) {
            i++;
        }

        if (i == n)
            return 0;

        bool negative = false;
        if (s[i] == '-') {
            negative = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        } else if (!isdigit(s[i])) {
            return 0;
        }

        if (i == n)
            return 0;

        // skip all leading zeros
        while (i < n && s[i] == 0) {
            i++;
        }

        if (i == n)
            return 0;

        int value = 0;
        int min = INT_MIN / 10;
        int max = INT_MAX / 10;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';//get the digits from ASCCI values

            if (!negative) {
                if (value > INT_MAX / 10 ||
                    (value == INT_MAX / 10 && digit > 7))
                    return INT_MAX;

                value = value * 10 + digit;
            } else {
                if (value < INT_MIN / 10 ||
                    (value == INT_MIN / 10 && digit > 8))
                    return INT_MIN;

                value = value * 10 - digit;
            }

            i++;
        }
        return value;
    }
};