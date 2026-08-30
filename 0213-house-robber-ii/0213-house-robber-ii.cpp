class Solution {
public:

    int solve(vector<int>& nums, int s, int e) {
        int prev2 = nums[s];
        int prev1 = max(nums[s], nums[s+1]);

        for(int i = s + 2; i <= e; i++){
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        int c1 = solve(nums, 0, n-2);
        int c2 = solve(nums, 1, n-1);

        return max(c1, c2);
    }
};