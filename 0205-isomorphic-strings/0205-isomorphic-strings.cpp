class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> charIdxS;
        unordered_map<char, int> charIdxT;

        for(int i = 0; i < s.length(); i++) {

            // if not already found in map then add it char-> idx
            if(charIdxS.find(s[i]) == charIdxS.end() ) {
                charIdxS[s[i]] = i;
            }

            if(charIdxT.find(t[i]) == charIdxT.end() ) {
                charIdxT[t[i]] = i;
            }

            if(charIdxS[s[i]] != charIdxT[t[i]]) {
                return false;
            }
        }

        return true;
    }
};