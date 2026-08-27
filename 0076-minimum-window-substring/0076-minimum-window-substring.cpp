class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT;
        for(auto &s : t) {
            countT[s]++;
        }

        unordered_map<char, int> win;
        int have = 0;
        int need = countT.size();

        int resLen = INT_MAX;
        pair<int, int> res = {-1, -1};
        
        int l = 0;

        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            win[c]++;

            if(countT.count(c) && win[c] == countT[c]) {
                have++; // currently how many chars meet the requirement
            }

            while(need == have) {
                if((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                win[s[l]]--;
                if (countT.count(s[l]) && win[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};