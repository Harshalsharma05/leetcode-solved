class Solution {
public:
    int largestInteger(int n, int s) {
        int m = 1;
        int n1 = n;

        while(n1 > 1) {
            m *= 10;
            n1--;
        }
        cout << m;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(s <= 9) {
                ans = ans + s * m;
                return ans;
            }
            else {
                ans += 9 * m;
                s -= 9;
                m /= 10;

            }
            
        }

        return -1;
    }
};