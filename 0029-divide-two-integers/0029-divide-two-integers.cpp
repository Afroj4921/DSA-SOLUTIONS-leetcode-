class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor >= 0) sign = false;

        long long n = abs((long long) dividend);
        long long d = abs((long long) divisor);
        long long ans = 0;

        while(n >= d){
            long long cnt = 0;
            while(n >= (d<<(cnt+1)))
                cnt++;
            ans += (1 <<cnt);
            n -= (d << cnt);
        }

        if(ans == (1<<31) && sign){
            return INT_MAX;
        }
        if(ans == (1<<31) && !sign){
            return INT_MIN;
        }

        return sign ? ans : -ans;
    }
};