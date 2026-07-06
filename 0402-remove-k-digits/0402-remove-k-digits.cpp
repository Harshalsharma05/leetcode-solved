class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n) return "0";

        string st;

        for(int i = 0; i < n; i++) {
            
            while(!st.empty() && k > 0 && (st.back() - '0') > (num[i] - '0')) {
                st.pop_back();
                k = k - 1;
            }
            st.push_back(num[i]);
        }

        while (k > 0){
            st.pop_back();
            k = k - 1;
        }

        int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }

        st = st.substr(i);

        if(st.empty()) return "0";

        return st;
    }
};