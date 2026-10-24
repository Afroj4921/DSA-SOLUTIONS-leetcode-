class Solution {
public:
    int findDays(string date, vector<int>& cumMonthDays){
        int month = stoi(date.substr(0, 2));
        int days = stoi(date.substr(3));

        return cumMonthDays[month-1] + days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDdays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cumMonthDays(13, 0);

        cumMonthDays[1] = 31;
        for(int i=2; i<=12; i++){
            cumMonthDays[i] = cumMonthDays[i-1] + monthDdays[i-1];
        }

        int arriveAliceDay = findDays(arriveAlice, cumMonthDays);
        int leaveAliceDay = findDays(leaveAlice, cumMonthDays);
        int arriveBobDay = findDays(arriveBob, cumMonthDays);
        int leaveBobDay = findDays(leaveBob, cumMonthDays);

        int overLapDays = min(leaveAliceDay, leaveBobDay)  - max(arriveAliceDay, arriveBobDay) + 1;

        return overLapDays < 0 ? 0 : overLapDays;
    }
};