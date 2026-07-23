class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> freq;
        string ans = "";

        for(char ch : s) {
            freq[ch]++;
        }

        int n = s.size();
        for (auto it : freq) {
            maxHeap.push({it.second, it.first});
        }

        while(!maxHeap.empty()) {
            auto topE = maxHeap.top();
            while(topE.first > 0) {
                ans.push_back(topE.second);
                topE.first -= 1;
            }
            maxHeap.pop();
        }

        return ans;
    }
};