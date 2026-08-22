class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int maxi = -1;
        while(l < r) {
            int curr = (r-l) * min(height[l], height[r]);
            maxi = max(maxi, curr);

            if(height[l] < height[r]) l++;
            else r--;
        }

        return maxi;
    }
};