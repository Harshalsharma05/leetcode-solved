class Solution {
public:

    vector<int> findNSE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n); // to store idx of nse's of all elements

        stack<int> st;

        for(int i=n-1;i>=0;i--) {
            
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i); // push the idx
        }
        return ans;
    }

    // find prev smaller ele
    vector<int> findPSE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i=0;i<n;i++) {
            
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i); 
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        
        int maxArea = 0;
        int currA = 0;

        for (int i = 0; i < n; i++) {
            currA = heights[i] * (nse[i] - pse[i] - 1);
            maxArea = max(maxArea, currA);
        }

        return maxArea;
    }
};