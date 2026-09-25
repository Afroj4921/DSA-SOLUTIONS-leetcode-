class Solution {
public:
    string s;
    int n;
    int idx = 0;

    set<string> getUnit(){
        set<string> result;

        if(s[idx] == '{'){
            idx++;
            result = performUnion();
        }else{
            result = {string(1, s[idx])};
        }

        idx++;
        return result;
    }

    set<string> performConCat(){
        set<string> result {""};

        while(idx < n && (s[idx] == '{' || isalpha(s[idx]))){
            set<string> temp = getUnit();

            set<string> conCatRes;
            for(const string& left : result){
                for(const string& right : temp){
                    conCatRes.insert(left+right);
                }
            }
            result = conCatRes;
        }
        return result;
    }

    set<string> performUnion(){
        set<string> result;
        while(true){
            set<string> temp = performConCat();
            result.insert(temp.begin(), temp.end());

            if(idx < n && s[idx] == ','){
                idx++;
            }else{
                break;
            }
        } 
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        n = expression.size();
        s = expression;
        idx = 0;

        set<string> st = performUnion();
        vector<string> result(st.begin(), st.end());
        return result;
    }
};