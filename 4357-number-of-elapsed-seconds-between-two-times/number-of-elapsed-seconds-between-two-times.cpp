class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hours = stoi(endTime.substr(0,2)) - stoi(startTime.substr(0,2));
        int min = stoi(endTime.substr(3,2)) - stoi(startTime.substr(3,2));
        int sec = stoi(endTime.substr(6,2)) - stoi(startTime.substr(6,2));

        return hours*3600 + min*60 + sec;
    }
};