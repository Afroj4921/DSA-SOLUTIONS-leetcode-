class Solution {
public:
    bool rabinKarp(string &text, string &pattern){
        int n = text.size();
        int m = pattern.size();

        if(m > n) return false;

        const int base = 26;
        const int mod  = 1e9 + 7;

        long long patternHash = 0;
        long long textHash = 0;
        long long power = 1;

        //cal base^(m-1)
        for(int i=0; i<m-1; i++)
            power = (power * base) % mod;
        
        //Initial hash
        for(int i=0; i<m; i++){
            patternHash = (patternHash * base + pattern[i]) % mod;
            textHash = (textHash * base + text[i]) % mod;
        }

        for(int i=0; i<=n-m; i++){
            // if hash match, verify characters
            if(patternHash == textHash){
                if(text.substr(i, m) == pattern)
                    return true;
            }

            // roll the hash
            if(i < n-m){
                textHash = (textHash - text[i] * power % mod + mod) % mod;
                textHash = (textHash * base + text[i+m]) % mod;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;

        int repeat = 1;
        string ans = a;

        while(ans.size() < b.size()){
            ans += a;
            repeat++;
        }
        // Rabin Karp search
        if(rabinKarp(ans, b)){
            return repeat;
        }
        //ans +a , Rabin karp search
        ans += a;
        if(rabinKarp(ans, b)){
            return repeat+1;
        }

        return -1;
    }
};