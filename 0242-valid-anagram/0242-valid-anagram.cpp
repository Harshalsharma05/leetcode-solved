class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> cnt;

        for (char ch : s) {
            cnt[ch] = cnt[ch] + 1;
        }

        for (char ch : t) {
            if (cnt.find(ch) == cnt.end() || cnt[ch] == 0) {
                return false;
            }
            cnt[ch] = cnt[ch] - 1;
        }

        return true; 
    }
};