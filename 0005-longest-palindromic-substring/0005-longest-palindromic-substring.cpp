class Solution {
public:
    string expandCenter(string s, int l, int r) {
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }

        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        
        string max_str = s.substr(0,1);

        for(int i = 0; i < n; i++) {
            string odd = expandCenter(s, i, i);
            string even = expandCenter(s, i, i+1);

            if(odd.length() > max_str.length()) {
                max_str = odd;
            }

            if(even.length() > max_str.length()) {
                max_str = even;
            }
        }

        return max_str;
    }
};