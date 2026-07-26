class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;

        int tempStart = 0;
        int start = 0;
        int end = 0;

        for(int i = 0; i<n; i++){
            sum += nums[i];

            if(sum > maxSum) {
                maxSum = sum;
                start = tempStart;
                end = i;
            }

            if(sum < 0){
                sum = 0;
                tempStart = i + 1;
            }
        }

        for(int i = start; i <= end; i++) { // to print the subarray containing max sum
            cout << nums[i] << " ";
        }

        return maxSum;
    }
};