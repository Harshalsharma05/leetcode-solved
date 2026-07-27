class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int x1 = x;
        long rev=0;
        int d;
        while(x1>0){
            rev=(rev*10) + x1%10;
            x1=x1/10;
        }
        
        cout << rev;
        
        if(rev == x) {
            return true;
        }

        return false;
    }
};