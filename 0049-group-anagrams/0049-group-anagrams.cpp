class Solution {
public:

    // using hash table, keeping the char freq array of each str as the KEY and grouping strings acc to the key
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }

    
    // brute force - to sort all the string to use them as a key and group them using hash map
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     unordered_map<string, vector<string>> mpp;
    //     for(const auto& s : strs) {
    //         string sortedS = s;
    //         sort(sortedS.begin(), sortedS.end());
    //         mpp[sortedS].push_back(s);
    //     }

    //     vector<vector<string>> res;

    //     for(auto &p : mpp) {
    //         res.push_back(p.second);
    //     }

    //     return res;
    // }
};