class Solution {
public:
    bool checkAnagram(vector<int> &a,vector<int> &b)
    {
        for(int i=0;i<26;i++)
        {
            if(a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) {
            return {};
        }

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);
        vector<int> ans;

        for(auto &it : p) {
            freqP[it - 'a']++;
        }

        int start = 0, end = 0;

        while(end < s.size()) {
            
            freqS[s[end] - 'a']++;
            if(end - start + 1 == p.size()) {
                if(checkAnagram(freqS, freqP)) {
                    ans.push_back(start);
                }
            }
            if(end - start + 1 < p.size())
            {
                end++;
            }
            else
            {
                freqS[s[start] - 'a']--;
                start++;
                end++;
            }
        }
        return ans;
    }
};