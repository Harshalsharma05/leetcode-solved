class Solution {
public:
    double power(double x, long long n) {
        if(n == 0) return 1.00;
        if(n == 1) return x;

        if(n % 2 == 0) return power(x * x, n/2); // if pow is even

        return x * power(x, n-1); // if pow is negative
    }

    double myPow(double x, int n) {
        long long num = n;
        if(num < 0) {
            return (1.0 / power(x, -1 * num)); // 1 / x^n
        }

        return power(x, num);
    }
};