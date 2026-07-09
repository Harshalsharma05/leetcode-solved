class Solution {
public:

    // vector<int> findNSE(const vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> ans(n); // to store idx of nse's of all elements

    //     stack<int> st;

    //     for(int i=n-1;i>=0;i--) {
            
    //         while(!st.empty() && arr[st.top()] >= arr[i]) {
    //             st.pop();
    //         }
    //         ans[i] = !st.empty() ? st.top() : n;
    //         st.push(i); // push the idx
    //     }
    //     return ans;
    // }

    // // find prev smaller ele
    // vector<int> findPSE(const vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> ans(n);

    //     stack<int> st;

    //     for(int i=0;i<n;i++) {
            
    //         while(!st.empty() && arr[st.top()] >= arr[i]) {
    //             st.pop();
    //         }
    //         ans[i] = !st.empty() ? st.top() : -1;
    //         st.push(i); 
    //     }
    //     return ans;
    // }

    // brute force soln where precomputation of nse and pse is required

    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
        
    //     vector<int> nse = findNSE(heights);
    //     vector<int> pse = findPSE(heights);
        
    //     int maxArea = 0;
    //     int currA = 0;

    //     for (int i = 0; i < n; i++) {
    //         currA = heights[i] * (nse[i] - pse[i] - 1);
    //         maxArea = max(maxArea, currA);
    //     }

    //     return maxArea;
    // }

    // optimized soln computing nse and pse on the go
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        int nse, pse;

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int ele = st.top(); // will calculate area for this ele 
                st.pop();

                // computing nse and pse of the element
                nse = i;
                pse = st.empty() ? -1 : st.top();

                maxArea = max((heights[ele] * (nse - pse - 1)), maxArea);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int nse = n;
            int ele = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();

            maxArea = max((heights[ele] * (nse - pse - 1)), maxArea);
        }

        return maxArea;
    }
};