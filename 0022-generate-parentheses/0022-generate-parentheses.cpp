class Solution {
public:

    void backtrack(string curr, int op, int cl, int n, vector<string>& res) {
        if(curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if(op < n) backtrack(curr + '(', op + 1, cl, n, res);
        if(cl < op) backtrack(curr + ')', op, cl + 1, n, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", 0, 0, n, res);
        return res;
    }
};