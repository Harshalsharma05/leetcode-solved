class Solution {
public:

    int func(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int l = 0, r = 0, cnt = 0;

        while(r < nums.size()) {
            mpp[nums[r]]++;

            while(mpp.size() > k) { // keep shrinking the window until the cond is not satisfied of <= or >= K

                mpp[nums[l]]--;

                if(mpp[nums[l]] == 0) { // if some ele freq reaches zero it is not the part of the ans so remove it
                    mpp.erase(nums[l]);
                }

                l++; // increment the left ptr to shrink the window until cond will satisfy
            }

            cnt += (r - l + 1); // incr cnt by all the subarrays <= or >= K
            r++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // to find subarraysWithKDistinct we subtract subarrays with <= K distinct and <= K-1

        return func(nums, k) - func(nums, k-1);
    }
};