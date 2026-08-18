class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> pref(n);
        // vector<int> suff(n);

        // pref[0] = 1;
        // suff[n-1] = 1;

        // for(int i = 1; i < n; i++) {
        //     pref[i] = nums[i - 1] * pref[i - 1];
        // }

        // for(int i = n-2; i >= 0; i--) { // start from last 2nd ele
        //     suff[i] = nums[i + 1] * suff[i + 1];
        // }

        // for(int i = 0; i < n; i++) {
        //     nums[i] = pref[i] * suff[i];
        // }

        // return nums;

        // calculating pref and suff without extra space in linear time
        int n = nums.size();
        vector<int> pref(n);

        // first pass to calc pref product array
        pref[0] = 1;
        for(int i = 1; i < n; i++) {
            pref[i] = nums[i-1] * pref[i-1];
        }

        // second pass, we multiply each pref[i] with the product of all elements to the right of i (postfix product).
        int postFix = 1;
        for(int i = n-1; i >= 0; i--) {
            pref[i] *= postFix;
            postFix *= nums[i];
        }

        return pref;
    }
};