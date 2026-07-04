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
            st.push(i); // push the idx of the current ele
        }
        return ans;
    }

    // find prev smaller or equal ele to handle edge case like [1, 1] to not count same subarray twice
    vector<int> findPSEE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i=0;i<n;i++) {
            
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i); 
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        static constexpr int mod = 1000000007;
        int n = arr.size();

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int sum = 0;

        for(int i = 0; i < n; i++) {
            
            int left = i - psee[i]; // count contribution from left
            int right = nse[i] - i; // count contri from right

            long long freq = left *right * 1LL; //  total freq of ele in subarrays

            int val = (freq*arr[i]*1LL) % mod; // final total value with contribution of a ele

            sum = (sum + val) % mod; // adding value to the sum
        }
        return sum;
    }
};