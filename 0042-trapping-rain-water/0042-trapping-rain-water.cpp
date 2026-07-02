class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> arr = height;
        int n = height.size();
        int lmax = 0, rmax = 0, total = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            if (arr[l] <= arr[r]) {
                if (lmax > arr[l]) {
                    total += lmax - arr[l];
                } else {
                    lmax = arr[l];
                }
                l = l + 1;
            } else {
                if (rmax > arr[r]) {
                    total += rmax - arr[r];
                } else {
                    rmax = arr[r];
                }
                r = r - 1;
            }
        }

        return total;
    }
};