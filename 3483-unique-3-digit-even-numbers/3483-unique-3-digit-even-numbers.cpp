class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i != j && j != k && i != k){
                        int currNum = 0;
                        currNum *= 10 , currNum += digits[i];
                        currNum *= 10 , currNum += digits[j];
                        currNum *= 10 , currNum += digits[k];

                        if(currNum >= 100 && (currNum % 2 == 0)){
                            st.insert(currNum);
                        }
                    }
                }
            }
        }
        return st.size();
        
    }
};