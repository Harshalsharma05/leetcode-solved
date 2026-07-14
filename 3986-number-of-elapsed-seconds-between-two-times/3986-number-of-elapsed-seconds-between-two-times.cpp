class Solution {
public:
    int convertToSec(string s) {
        string hr = s.substr(0, 2);
        string min = s.substr(3, 2);
        string sec = s.substr(6, 2);

        int h = stoi(hr);
        int m = stoi(min);
        int se = stoi(sec);

        return ((h * 60 * 60) + (m * 60) + se);
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        int start = convertToSec(startTime);
        int end = convertToSec(endTime);

        return (end - start);
    }
};