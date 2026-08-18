class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(), nums.end());

        // int currcnt = 0;
        // int longest = 0;
        // int lastsmall = INT_MIN;

        // for(int i = 0; i < n; i++){
        //     if(nums[i]-1 == lastsmall){
        //         currcnt++;
        //         lastsmall = nums[i];

        //     }else if(nums[i] != lastsmall){
        //         currcnt = 1;
        //         lastsmall = nums[i];
        //     }

        //     longest = max(longest, currcnt);
        // }

        // return longest;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxi = 0;

        for(int num : numSet) {
            if(numSet.find(num-1) == numSet.end()) { // if num - 1 not in the set then can be used as start of the sequence
                int len = 1;
                while(numSet.find(num + len) != numSet.end()) {
                    len += 1;
                }
                maxi = max(maxi, len);
            }
        }
        
        return maxi;
    }
};