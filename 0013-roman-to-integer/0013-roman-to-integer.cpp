class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val;
        val['I']= 1;
        val['V']= 5;
        val['X']= 10;
        val['L']= 50; 
        val['C']= 100; 
        val['D']= 500; 
        val['M']= 1000;

        int res = 0;
        for(int i = s.size()-1; i >=0; i--){
            int curr = val[s[i]];
            int next = (i+1 < s.size()) ? val[s[i+1]] : 0;

            if(curr < next) {
                res -= curr;
            } else {
                res += curr;
            }
        }

        return res;
    }
};