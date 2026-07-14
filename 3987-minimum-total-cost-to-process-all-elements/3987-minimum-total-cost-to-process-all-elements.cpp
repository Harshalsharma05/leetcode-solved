class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        long long avail = k;
        long long total = 0;
        long long oprDone = 0;
        long long shortage, opr;

        for(int i = 0; i < n; i++) {
            if(nums[i] <= avail) {
                avail = avail - nums[i];
            } else {
                shortage = 1LL*nums[i] - 1LL*avail;
                opr = (shortage + k - 1) / k;

                long long first = oprDone + 1;
                long long last = oprDone + opr;
                oprDone += opr;
                __int128 cost;
                if (opr % 2 == 0)
                    cost = (__int128)(opr / 2) * (first + last);
                else
                    cost = (__int128)opr * ((first + last) / 2);

                total = (total + (long long)(cost % mod)) % mod;
                avail += k * opr * 1LL;
                avail -= nums[i]; 
            }
        }

        return (total % mod) * 1LL;
    }
};