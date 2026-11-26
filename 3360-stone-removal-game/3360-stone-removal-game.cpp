class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;

        int stones = 10;

        while(n >= stones){
            n -= stones;
            stones--;
            alice = !alice;
        }

        return !alice;
    }
};