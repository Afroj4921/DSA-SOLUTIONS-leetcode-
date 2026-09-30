class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int d = 0;
        vector<int> result(n);
        for(int i=0; i<n; i++){
            if(seq[i] == '('){
                d++;
                result[i] = (d%2 == 0) ? 0 : 1;
            }else{
                result[i] = (d%2 == 0) ? 0 : 1;
                d--;
            }
        }
        return result;
    }
};