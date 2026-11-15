class Solution {
public:
    int CntSetBits(int n){
        int cnt = 0;
        while(n != 0){
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }

    int hammingDistance(int x, int y) {
        int n = x^y;

        return CntSetBits(n);
    }
};