class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n/2;
        int lsum = 0, rsum = 0;
        int lq = 0, rq = 0;

        for(int i=0; i<mid; i++){
            if(num[i] == '?') lq++;
            else lsum += num[i] - '0';
        }
        for(int j=mid; j<n; j++){
            if(num[j] == '?') rq++;
            else rsum += num[j] - '0';
        }

        if(lq == rq){
            return lsum != rsum;
        }
        return 2 * (lsum -rsum) != 9 * (rq - lq);
    }
};