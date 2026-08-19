class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();

        string ans = "";

        for(int i = 0; i < n; i++) {
            if(isalnum(s[i])) {
                ans += tolower(s[i]);
            }
        }

        string revS(ans.rbegin(), ans.rend());

        return revS == ans;
    }
};