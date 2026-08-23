class Solution {
public:

    int solve(int n){

        // if(n == 0) return 1;
        // if(n == 1) return 1;

        // int left = solve(n - 1);
        // int right = solve(n - 2);

        // return left + right;

        if(n <= 3) return n;

        int prev2 = 2;
        int prev = 3;
        int curr = 0;

        for(int i = 3; i < n ; i++){
            curr = prev + prev2;

            prev2 = prev;
            prev = curr;
        }

        return curr;
    }

    int climbStairs(int n) {
        return solve(n);
    }
};