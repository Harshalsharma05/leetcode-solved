class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = INT_MAX;
        int diff = INT_MAX;
        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            int l = i+1, r = n - 1;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if(sum < target) {
                    l++;
                }else if (sum > target) {
                    r--;
                }

                int oldDiff = diff;
                diff = abs(sum - target);

                if(oldDiff >= diff) {
                    ans = sum;
                } else {
                    diff = oldDiff;
                }

                if(diff == 0) {
                    return ans;
                }
            }
        }

        return ans;
    }
};