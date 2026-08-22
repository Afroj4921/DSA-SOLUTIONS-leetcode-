class Solution {
public:
    bool checkDivisibility(int n) {
        long long num = n;
        long long sum = 0;
        long long prod = 1;
        while(num > 0){
            int d = num%10;
            sum += d;
            prod *= d;
            num /= 10;
        }
        if(sum + prod == 0) return false;
        return (n % (sum + prod) == 0);
    }
};