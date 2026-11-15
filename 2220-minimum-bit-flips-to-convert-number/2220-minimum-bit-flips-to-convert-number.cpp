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

    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        return CntSetBits(n);
    }
};