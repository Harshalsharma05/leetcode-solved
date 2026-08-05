class Solution {
public:
    int getNext(int n) {
        int ans = 0;

        while(n > 0) {
            int d = n % 10;
            n /= 10;
            ans += d * d;
        }
        return ans;
    }

    bool isHappy(int n) { // can eventually lead to 1 or gets stuck in a cycle
        int slow = n;
        int fast = getNext(n);

        // 2 pointers as if linked list to track 2 no at a time
        // if not result in a cycle fast ptr will end up at 1
        // and if stuck in a cycle (coming at a same no) then fast and slow will be at the same number so return false

        while(fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }
};