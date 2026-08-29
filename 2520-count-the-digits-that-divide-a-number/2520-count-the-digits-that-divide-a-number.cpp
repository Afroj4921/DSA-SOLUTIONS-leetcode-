class Solution {
public:
    int countDigits(int num) {
        int n = num;
        int count = 0;
        while(n > 0){
            int lastDig = n%10;
            if(num%lastDig == 0) count++;
            n /= 10;
        }
        return count;
    }
};