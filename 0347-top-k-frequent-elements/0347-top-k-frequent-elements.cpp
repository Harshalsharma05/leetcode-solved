class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cntMpp;
        vector<vector<int>> freq(nums.size() + 1); // a number max freq = size of the array

        for(const auto& e : nums) {
            cntMpp[e] += 1;
        }

        // bucket sort - here bucket is the maximum times a num can appear in the array, i.e, equal to the length of the array
        for(const auto& entry : cntMpp) {
            freq[entry.second].push_back(entry.first);
            // at each index we store all numbers that appear exactly that many times
            // eg freq[2] = [1, 2] --> 1 and 2 appears 2 times each in the array
        }

        vector<int> res;

        for(int i = freq.size()-1; i > 0; i--) {
            for(int n : freq[i]) {
                res.push_back(n);

                if(res.size() == k) return res;
            }
        }

        return res;
    }
};